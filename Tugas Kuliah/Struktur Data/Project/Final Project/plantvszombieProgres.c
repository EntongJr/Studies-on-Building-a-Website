// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Hafidz Ali Murtadho
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nama file penyimpanan
#define FILENAME "pvz_data.txt"

// Deklarasi Struktur Node Tanaman
typedef struct Node {
    int id_tanaman;
    char nama_tanaman[50];
    int biaya_matahari; 
    struct Node *kiri;
    struct Node *kanan;
} Node;

// Variabel Global untuk ID Tanaman Otomatis
int next_id = 1;

// --- PROTOTYPE fungsi (penting: beberapa fungsi dipakai sebelum didefinisikan) ---
Node* insert(Node *root, int id, const char *nama, int biaya);
Node* deleteNode(Node *root, int biaya);
Node* search(Node *root, int biaya, const char *posisi, int print_detail);
void saveToFile(Node *root);

// --- FUNGSI UTILITY BST & FILE I/O ---

Node* createNode(int id, const char *nama, int biaya) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Gagal alokasi memori.\n");
        exit(1);
    }
    newNode->id_tanaman = id;
    strncpy(newNode->nama_tanaman, nama, sizeof(newNode->nama_tanaman) - 1);
    newNode->nama_tanaman[sizeof(newNode->nama_tanaman) - 1] = '\0';
    newNode->biaya_matahari = biaya;
    newNode->kiri = NULL;
    newNode->kanan = NULL;
    return newNode;
}

Node* findMinNode(Node *node) {
    Node *current = node;
    while (current && current->kiri != NULL) {
        current = current->kiri;
    }
    return current;
}

// Fungsi Traversal untuk menulis data BST ke file (preorder)
void writeToFileTraversal(Node *root, FILE *fp) {
    if (root != NULL) {
        fprintf(fp, "%d,%s,%d\n", root->id_tanaman, root->nama_tanaman, root->biaya_matahari);
        writeToFileTraversal(root->kiri, fp);
        writeToFileTraversal(root->kanan, fp);
    }
}

// Fungsi untuk menyimpan seluruh data BST ke file
void saveToFile(Node *root) {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error: Gagal membuka file %s untuk menulis.\n", FILENAME);
        return;
    }
    writeToFileTraversal(root, fp);
    fclose(fp);
    printf("Perubahan data berhasil disimpan ke file %s.\n", FILENAME);
}

// Fungsi untuk memuat data dari file ke BST
Node* loadFromFile(Node *root) {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("File %s tidak ditemukan. Membuat BST kosong.\n", FILENAME);
        return NULL;
    }

    int id, biaya, max_id = 0;
    char nama[50];

    printf("Memuat data dari file %s...\n", FILENAME);

    // Baca data per baris: format id,nama,biaya
    while (fscanf(fp, "%d,%49[^,],%d\n", &id, nama, &biaya) == 3) {
        root = insert(root, id, nama, biaya);
        if (id > max_id) {
            max_id = id;
        }
    }

    // Update next_id agar penambahan data baru tidak bentrok
    next_id = max_id + 1;

    fclose(fp);
    return root;
}

// --- FUNGSI BST ---

// 1. OPERASI INSERT
Node* insert(Node *root, int id, const char *nama, int biaya) {
    if (root == NULL) {
        return createNode(id, nama, biaya);
    }

    if (biaya < root->biaya_matahari) {
        root->kiri = insert(root->kiri, id, nama, biaya);
    } else if (biaya > root->biaya_matahari) {
        root->kanan = insert(root->kanan, id, nama, biaya);
    } 
    return root;
}

// 2. OPERASI DELETE
Node* deleteNode(Node *root, int biaya) {
    if (root == NULL) {
        return root;
    }

    if (biaya < root->biaya_matahari) {
        root->kiri = deleteNode(root->kiri, biaya);
    } else if (biaya > root->biaya_matahari) {
        root->kanan = deleteNode(root->kanan, biaya);
    } else {
        printf("Deleted: %s (Sun: %d)\n", root->nama_tanaman, root->biaya_matahari);

        if (root->kiri == NULL) {
            Node *temp = root->kanan;
            free(root);
            return temp;
        } else if (root->kanan == NULL) {
            Node *temp = root->kiri;
            free(root);
            return temp;
        }

        Node *temp = findMinNode(root->kanan);
        root->id_tanaman = temp->id_tanaman;
        strncpy(root->nama_tanaman, temp->nama_tanaman, sizeof(root->nama_tanaman) - 1);
        root->nama_tanaman[sizeof(root->nama_tanaman) - 1] = '\0';
        root->biaya_matahari = temp->biaya_matahari;
        root->kanan = deleteNode(root->kanan, temp->biaya_matahari);
    }
    return root;
}

// 3. OPERASI SEARCH (mengembalikan Node* atau NULL)
Node* search(Node *root, int biaya, const char *posisi, int print_detail) {
    if (root == NULL) {
        if (print_detail) {
            printf("Search: Tanaman dengan Biaya %d tidak ditemukan.\n", biaya);
        }
        return NULL;
    }

    if (root->biaya_matahari == biaya) {
        if (print_detail) {
            printf("\n**Tanaman Ditemukan!**\n");
            printf("----------------------------------------\n");
            printf("| ID: %d | Nama: %s\n", root->id_tanaman, root->nama_tanaman);
            printf("| Biaya Matahari: %d\n", root->biaya_matahari);
            printf("| Posisi Relatif dari Akar: %s\n", posisi);
            printf("----------------------------------------\n");
        }
        return root;
    }

    char next_pos[200];
    if (strcmp(posisi, "Akar") == 0) {
        sprintf(next_pos, "Akar -> %s", (biaya < root->biaya_matahari) ? "Kiri" : "Kanan");
    } else {
        sprintf(next_pos, "%s -> %s", posisi, (biaya < root->biaya_matahari) ? "Kiri" : "Kanan");
    }

    if (biaya < root->biaya_matahari) {
        return search(root->kiri, biaya, next_pos, print_detail);
    } else {
        return search(root->kanan, biaya, next_pos, print_detail);
    }
}

// 4. OPERASI VIEW
void printTreeStructure(Node *root, int level) {
    int i;
    if (root == NULL) {
        return;
    }

    printTreeStructure(root->kanan, level + 1);

    for (i = 0; i < level; i++) {
        printf("    "); 
    }
    
    printf("--> ID: %d\n", root->id_tanaman);

    printTreeStructure(root->kiri, level + 1);
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->kiri);
        printf("| %-2d | %-20s | %-15d |\n", 
            root->id_tanaman, root->nama_tanaman, root->biaya_matahari);
        inorderTraversal(root->kanan);
    }
}

void view(Node *root) {
    if (root == NULL) {
        printf("\nBST kosong.\n");
        return;
    }

    // Bagian 1: Visualisasi Pohon (Hanya ID)
    printf("\n=========================================\n");
    printf("  VISUALISASI POHON BST (Hanya ID Tanaman)\n");
    printf("  Akar/Root: ID %d\n", root->id_tanaman);
    printf("=========================================\n");
    printTreeStructure(root, 0);
    printf("=========================================\n");

    // Bagian 2: Data Lengkap
    printf("\nDATA LENGKAP TANAMAN (Diurutkan berdasarkan Biaya Matahari)\n");
    printf("-----------------------------------------\n");
    printf("| ID | Nama Tanaman         | Biaya Matahari  |\n");
    printf("-----------------------------------------\n");
    inorderTraversal(root);
    printf("-----------------------------------------\n");
}

// Fungsi Utama
int main() {
    Node *root = NULL;
    int choice, biaya;
    char nama[50];
    
    // Muat data dari file saat program dimulai
    root = loadFromFile(root);
    
    // Jika file kosong atau gagal dimuat, masukkan data awal
    if (root == NULL) {
        printf("\nMembuat 7 node tanaman awal karena file kosong.\n");
        root = insert(root, next_id++, "Peashooter", 100); 
        root = insert(root, next_id++, "Sunflower", 50);
        root = insert(root, next_id++, "Cherry_Bomb", 150);
        root = insert(root, next_id++, "Potato_Mine", 25);
        root = insert(root, next_id++, "Snow_Pea", 175);
        root = insert(root, next_id++, "Repeater", 200);
        root = insert(root, next_id++, "Grave_Buster", 75);
        // Simpan data awal ini ke file
        saveToFile(root);
    } else {
        printf("Data berhasil dimuat. Terdapat ID terakhir yang digunakan: %d.\n", next_id - 1);
    }

    do {
        printf("\n\n=== MENU BST PLANTS VS ZOMBIES ===\n");
        printf("1. Insert (Tambah Tanaman)\n");
        printf("2. Delete (Hapus Tanaman)\n");
        printf("3. Search (Cari Tanaman)\n");
        printf("4. View (Tampilkan BST Pohon dan Data)\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: 
                printf("\n--- INSERT TANAMAN ---\n");
                printf("Nama Tanaman: ");
                scanf("%49s", nama);
                printf("Biaya Matahari (Kunci BST): ");
                if (scanf("%d", &biaya) != 1) {
                    printf("Input biaya tidak valid.\n");
                    while (getchar() != '\n');
                    break;
                }
                
                if (search(root, biaya, "Akar", 0) == NULL) {
                    root = insert(root, next_id, nama, biaya);
                    next_id++;
                    saveToFile(root); // Simpan perubahan
                } else {
                    printf("Operasi Insert dibatalkan: Tanaman dengan Biaya %d sudah ada.\n", biaya);
                }
                break;
            case 2: 
                printf("\n--- DELETE TANAMAN ---\n");
                printf("Masukkan Biaya Matahari dari tanaman yang ingin dihapus: ");
                if (scanf("%d", &biaya) != 1) {
                    printf("Input biaya tidak valid.\n");
                    while (getchar() != '\n');
                    break;
                }
                
                // Cek apakah node ada
                if (search(root, biaya, "Akar", 0) != NULL) {
                    root = deleteNode(root, biaya);
                    saveToFile(root); // Simpan perubahan
                } else {
                    printf("Operasi Delete dibatalkan: Tanaman dengan Biaya %d tidak ditemukan.\n", biaya);
                }
                break;
            case 3: 
                printf("\n--- SEARCH TANAMAN ---\n");
                printf("Masukkan Biaya Matahari dari tanaman yang dicari: ");
                if (scanf("%d", &biaya) != 1) {
                    printf("Input biaya tidak valid.\n");
                    while (getchar() != '\n');
                    break;
                }

                search(root, biaya, "Akar", 1);
                break;
            case 4: 
                view(root);
                break;
            case 0:
                printf("\nTerima kasih. Program selesai.\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 0);

    return 0;
}
