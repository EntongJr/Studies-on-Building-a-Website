// 24081010297 Hafidz Ali Murtadho
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Node Mahasiswa
typedef struct Mahasiswa {
    int nim;
    char nama[50];
    struct Mahasiswa *left;
    struct Mahasiswa *right;
} Mahasiswa;

// Membuat node baru
Mahasiswa* buatNode(int nim, char nama[]) {
    Mahasiswa* baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    baru->nim = nim;
    strcpy(baru->nama, nama);
    baru->left = baru->right = NULL;
    return baru;
}

// Insert BST
Mahasiswa* insert(Mahasiswa* root, int nim, char nama[]) {
    if (root == NULL)
        return buatNode(nim, nama);

    if (nim < root->nim)
        root->left = insert(root->left, nim, nama);
    else if (nim > root->nim)
        root->right = insert(root->right, nim, nama);
    else
        printf("NIM %d sudah terdaftar!\n", nim);

    return root;
}

// Search
Mahasiswa* search(Mahasiswa* root, int nim) {
    if (root == NULL || root->nim == nim)
        return root;

    if (nim < root->nim)
        return search(root->left, nim);
    else
        return search(root->right, nim);
}

// Node minimum
Mahasiswa* minValueNode(Mahasiswa* node) {
    Mahasiswa* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete
Mahasiswa* deleteNode(Mahasiswa* root, int nim) {
    if (root == NULL)
        return root;

    if (nim < root->nim)
        root->left = deleteNode(root->left, nim);
    else if (nim > root->nim)
        root->right = deleteNode(root->right, nim);
    else {
        if (root->left == NULL) {
            Mahasiswa* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Mahasiswa* temp = root->left;
            free(root);
            return temp;
        }

        Mahasiswa* temp = minValueNode(root->right);
        root->nim = temp->nim;
        strcpy(root->nama, temp->nama);
        root->right = deleteNode(root->right, temp->nim);
    }
    return root;
}

// Inorder
void inorder(Mahasiswa* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("NIM: %d | Nama: %s\n", root->nim, root->nama);
        inorder(root->right);
    }
}

int main() {
    Mahasiswa* root = NULL;
    int pilihan, nim;
    char nama[50];
    char ulang;
    Mahasiswa* hasil;

    do {
        printf("\n=== MENU BST MAHASISWA ===\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Cari Data Mahasiswa\n");
        printf("3. Hapus Data Mahasiswa\n");
        printf("4. Tampilkan Data (Urut NIM)\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            do {
                printf("\nMasukkan NIM  : ");
                scanf("%d", &nim);
                printf("Masukkan Nama: ");
                scanf(" %[^\n]", nama);

                root = insert(root, nim, nama);

                printf("Tambah data lagi? (y/n): ");
                scanf(" %c", &ulang);

            } while (ulang == 'y' || ulang == 'Y');
            break;

        case 2:
            printf("Masukkan NIM yang dicari: ");
            scanf("%d", &nim);
            hasil = search(root, nim);
            if (hasil != NULL)
                printf("Data Mahasiswa Ditemukan -> NIM: %d | Nama: %s\n",
                    hasil->nim, hasil->nama);
            else
                printf("Data tidak ditemukan.\n");
            break;

        case 3:
            printf("Masukkan NIM yang dihapus: ");
            scanf("%d", &nim);
            root = deleteNode(root, nim);
            printf("Data Mahasiswa dengan NIM %d Telah Dihapus.\n", nim);
            break;

        case 4:
            printf("\nData Mahasiswa (Urut NIM):\n");
            inorder(root);
            break;

        case 5:
            printf("Program selesai.\n");
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);

    return 0;
}
