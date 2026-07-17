// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Hafidz Ali Murtadho
// 24081010301 Ahmadridloabdillah

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define FILENAME "pvz_data.txt"

/* ================= ENUM MODE ================= */
enum TreeMode {
    MODE_BST = 1,
    MODE_AVL = 2
};

/* ================= NODE ================= */
struct Node {
    int id_tanaman;
    char nama_tanaman[50];
    int biaya_matahari;
    int height;
    Node *kiri;
    Node *kanan;
};

TreeMode mode;
int next_id = 1;

/* ================= UTIL ================= */
int max(int a, int b) { return (a > b) ? a : b; }
int height(Node *n) { return n ? n->height : 0; }
int getBalance(Node *n) { return n ? height(n->kiri) - height(n->kanan) : 0; }

/* ================= ROTASI AVL ================= */
Node* rightRotate(Node *y) {
    Node *x = y->kiri;
    Node *T2 = x->kanan;

    x->kanan = y;
    y->kiri = T2;

    y->height = max(height(y->kiri), height(y->kanan)) + 1;
    x->height = max(height(x->kiri), height(x->kanan)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->kanan;
    Node *T2 = y->kiri;

    y->kiri = x;
    x->kanan = T2;

    x->height = max(height(x->kiri), height(x->kanan)) + 1;
    y->height = max(height(y->kiri), height(y->kanan)) + 1;

    return y;
}

/* ================= CREATE ================= */
Node* createNode(int id, const char *nama, int biaya) {
    Node *n = new Node;
    n->id_tanaman = id;
    strcpy(n->nama_tanaman, nama);
    n->biaya_matahari = biaya;
    n->height = 1;
    n->kiri = n->kanan = NULL;
    return n;
}

/* ================= BST INSERT ================= */
Node* insert(Node *root, int id, const char *nama, int biaya) {
    if (!root)
        return createNode(id, nama, biaya);

    if (id < root->id_tanaman)
        root->kiri = insert(root->kiri, id, nama, biaya);
    else if (id > root->id_tanaman)
        root->kanan = insert(root->kanan, id, nama, biaya);

    return root;
}

/* ================= AVL INSERT ================= */
Node* insertAVL(Node *node, int id, const char *nama, int biaya) {
    if (!node)
        return createNode(id, nama, biaya);

    if (id < node->id_tanaman)
        node->kiri = insertAVL(node->kiri, id, nama, biaya);
    else if (id > node->id_tanaman)
        node->kanan = insertAVL(node->kanan, id, nama, biaya);
    else
        return node;

    node->height = 1 + max(height(node->kiri), height(node->kanan));
    int balance = getBalance(node);

    if (balance > 1 && id < node->kiri->id_tanaman)
        return rightRotate(node);

    if (balance < -1 && id > node->kanan->id_tanaman)
        return leftRotate(node);

    if (balance > 1 && id > node->kiri->id_tanaman) {
        node->kiri = leftRotate(node->kiri);
        return rightRotate(node);
    }

    if (balance < -1 && id < node->kanan->id_tanaman) {
        node->kanan = rightRotate(node->kanan);
        return leftRotate(node);
    }

    return node;
}

/* ================= DELETE ================= */
Node* findMinNode(Node *node) {
    while (node->kiri)
        node = node->kiri;
    return node;
}

Node* deleteNode(Node *root, int id) {
    if (!root) return root;

    if (id < root->id_tanaman)
        root->kiri = deleteNode(root->kiri, id);
    else if (id > root->id_tanaman)
        root->kanan = deleteNode(root->kanan, id);
    else {
        if (!root->kiri) {
            Node *temp = root->kanan;
            delete root;
            return temp;
        } else if (!root->kanan) {
            Node *temp = root->kiri;
            delete root;
            return temp;
        }

        Node *temp = findMinNode(root->kanan);
        root->id_tanaman = temp->id_tanaman;
        strcpy(root->nama_tanaman, temp->nama_tanaman);
        root->biaya_matahari = temp->biaya_matahari;
        root->kanan = deleteNode(root->kanan, temp->id_tanaman);
    }
    return root;
}

Node* deleteAVL(Node *root, int id) {
    if (!root) return root;

    if (id < root->id_tanaman)
        root->kiri = deleteAVL(root->kiri, id);
    else if (id > root->id_tanaman)
        root->kanan = deleteAVL(root->kanan, id);
    else {
        if (!root->kiri || !root->kanan) {
            Node *temp = root->kiri ? root->kiri : root->kanan;
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node *temp = findMinNode(root->kanan);
            root->id_tanaman = temp->id_tanaman;
            strcpy(root->nama_tanaman, temp->nama_tanaman);
            root->biaya_matahari = temp->biaya_matahari;
            root->kanan = deleteAVL(root->kanan, temp->id_tanaman);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->kiri), height(root->kanan));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->kiri) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->kiri) < 0) {
        root->kiri = leftRotate(root->kiri);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->kanan) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->kanan) > 0) {
        root->kanan = rightRotate(root->kanan);
        return leftRotate(root);
    }

    return root;
}

/* ================= SEARCH ================= */
Node* searchByID(Node *root, int id, const char *posisi, int print) {
    if (!root) {
        if (print) cout << "Data tidak ditemukan\n";
        return NULL;
    }

    if (root->id_tanaman == id) {
        if (print) {
            cout << "\nID: " << root->id_tanaman
                << "\nNama: " << root->nama_tanaman
                << "\nBiaya: " << root->biaya_matahari
                << "\nPosisi: " << posisi << endl;
        }
        return root;
    }

    char next[100];
    sprintf(next, "%s -> Kiri", posisi);
    Node *found = searchByID(root->kiri, id, next, print);
    if (found) return found;

    sprintf(next, "%s -> Kanan", posisi);
    return searchByID(root->kanan, id, next, print);
}

/* ================= VIEW ================= */
void printAVL(Node *root, int space) {
    if (!root) return;
    space += 5;
    printAVL(root->kanan, space);
    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->id_tanaman << endl;
    printAVL(root->kiri, space);
}

void printBST(Node *root, int level) {
    if (!root) return;
    printBST(root->kanan, level + 1);
    for (int i = 0; i < level; i++) cout << "    ";
    cout << root->id_tanaman << endl;
    printBST(root->kiri, level + 1);
}

void inorder(Node *root) {
    if (root) {
        inorder(root->kiri);
        cout << "| " << root->id_tanaman
            << " | " << root->nama_tanaman
            << " | " << root->biaya_matahari << " |\n";
        inorder(root->kanan);
    }
}

void printListOnly(Node *root) {
    if (!root) {
        cout << "Data kosong\n";
        return;
    }

    cout << "\n[ LIST DATA ]\n";
    cout << "---------------------------------\n";
    cout << "| ID | Nama            | Biaya |\n";
    cout << "---------------------------------\n";
    inorder(root);
    cout << "---------------------------------\n";
}


void view(Node *root) {
    cout << "\nMODE: " << (mode == MODE_AVL ? "AVL TREE" : "BST") << endl;
    cout << "\n[ VISUAL TREE ]\n\n";

    if (!root) {
        cout << "Tree kosong\n";
        return;
    }

    if (mode == MODE_AVL) printAVL(root, 0);
    else printBST(root, 0);

    cout << "\n[ LIST DATA ]\n";
    cout << "---------------------------------\n";
    cout << "| ID | Nama            | Biaya |\n";
    cout << "---------------------------------\n";
    inorder(root);
    cout << "---------------------------------\n";
}

/* ================= FILE ================= */
void writeFile(Node *root, ofstream &fp) {
    if (root) {
        fp << root->id_tanaman << ","
            << root->nama_tanaman << ","
            << root->biaya_matahari << "\n";
        writeFile(root->kiri, fp);
        writeFile(root->kanan, fp);
    }
}

void saveToFile(Node *root) {
    ofstream fp(FILENAME);
    if (!fp) return;
    writeFile(root, fp);
    fp.close();
}

Node* loadFromFile(Node *root) {
    ifstream fp(FILENAME);
    if (!fp) return NULL;

    int id, biaya, maxid = 0;
    char nama[50];
    char comma;

    while (fp >> id >> comma &&
            fp.getline(nama, 50, ',') &&
            fp >> biaya) {
        fp.ignore();
        root = (mode == MODE_AVL) ?
                insertAVL(root, id, nama, biaya) :
                insert(root, id, nama, biaya);
        if (id > maxid) maxid = id;
    }

    next_id = maxid + 1;
    fp.close();
    return root;
}

/* ================= DEFAULT DATA ================= */
void insertDefaultData(Node **root) {
    struct {
        char nama[20];
        int biaya;
    } data[] = {
        {"Peashooter", 100},
        {"Sunflower", 50},
        {"CherryBomb", 150},
        {"Wallnut", 75},
        {"PotatoMine", 25},
        {"SnowPea", 175},
        {"Chomper", 125},
        {"Repeater", 200},
        {"Cactus", 225},
        {"Torchwood", 250}
    };

    for (int i = 0; i < 10; i++) {
        *root = (mode == MODE_AVL) ?
                insertAVL(*root, next_id, data[i].nama, data[i].biaya) :
                insert(*root, next_id, data[i].nama, data[i].biaya);
        next_id++;
    }
    saveToFile(*root);
}

/* ================= MAIN ================= */
int main() {
    int choice;

    while (1) {
        Node *root = NULL;

        cout << "\n=== PILIH MODE TREE ===\n";
        cout << "1. BST\n";
        cout << "2. AVL Tree\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice != 1 && choice != 2) continue;

        mode = (choice == 2) ? MODE_AVL : MODE_BST;
        next_id = 1;
        root = loadFromFile(root);
        if (!root) insertDefaultData(&root);

        int menu, id, biaya;
        char nama[50];

        do {
            cout << "\n=== MENU (" << (mode == MODE_AVL ? "AVL TREE" : "BST") << ") ===\n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Search\n";
            cout << "4. View\n";
            cout << "0. Return\n";
            cout << "Choose: ";
            cin >> menu;

            switch (menu) {
            case 1:
                cout << "Nama: ";
                cin >> nama;
                cout << "Biaya: ";
                cin >> biaya;

                root = (mode == MODE_AVL) ?
                        insertAVL(root, next_id, nama, biaya) :
                        insert(root, next_id, nama, biaya);
                next_id++;

                saveToFile(root);

                cout << "\nData berhasil ditambahkan!\n";
                printListOnly(root);   // <<< LIST SAJA

                break;

            case 2:
                cout << "ID: ";
                cin >> id;

                root = (mode == MODE_AVL) ?
                        deleteAVL(root, id) :
                        deleteNode(root, id);

                saveToFile(root);

                cout << "\nData setelah penghapusan:\n";
                printListOnly(root);   // <<< LIST SAJA

                break;

            case 3:
                cout << "ID: ";
                cin >> id;
                searchByID(root, id, "Akar", 1);
                break;

            case 4:
                view(root);
                break;
            }
        } while (menu != 0);
    }

    cout << "Program selesai.\n";
    return 0;
}