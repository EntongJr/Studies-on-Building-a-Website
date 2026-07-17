#include <iostream>
#include <algorithm>
using namespace std;

// ======================= DATA TANAMAN =======================
struct Tanaman {
    string nama;
    int harga;
};

// ======================= BST SECTION =========================
struct BSTNode {
    Tanaman data;
    BSTNode *left, *right;
};

BSTNode* bst_newNode(Tanaman t) {
    BSTNode* node = new BSTNode;
    node->data = t;
    node->left = node->right = NULL;
    return node;
}

BSTNode* bst_insert(BSTNode* root, Tanaman t) {
    if (!root) return bst_newNode(t);

    if (t.nama < root->data.nama)
        root->left = bst_insert(root->left, t);
    else if (t.nama > root->data.nama)
        root->right = bst_insert(root->right, t);

    return root;
}

BSTNode* bst_findMin(BSTNode* node) {
    while (node->left) node = node->left;
    return node;
}

BSTNode* bst_delete(BSTNode* root, string nama) {
    if (!root) return NULL;

    if (nama < root->data.nama)
        root->left = bst_delete(root->left, nama);
    else if (nama > root->data.nama)
        root->right = bst_delete(root->right, nama);
    else {
        if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }

        BSTNode* temp = bst_findMin(root->right);
        root->data = temp->data;
        root->right = bst_delete(root->right, temp->data.nama);
    }
    return root;
}

bool bst_search(BSTNode* root, string nama) {
    if (!root) return false;
    if (root->data.nama == nama) return true;

    if (nama < root->data.nama)
        return bst_search(root->left, nama);
    else
        return bst_search(root->right, nama);
}

void bst_print(BSTNode* node) {
    if (node) {
        bst_print(node->left);
        cout << "- " << node->data.nama << " [" << node->data.harga << "]\n";
        bst_print(node->right);
    }
}

// ======================= AVL SECTION =========================
struct AVLNode {
    Tanaman data;
    AVLNode *left, *right;
    int height;
};

AVLNode* avl_newNode(Tanaman t) {
    AVLNode* node = new AVLNode;
    node->data = t;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int avl_height(AVLNode* n) {
    return n ? n->height : 0;
}

int avl_balance(AVLNode* n) {
    return n ? avl_height(n->left) - avl_height(n->right) : 0;
}

AVLNode* avl_rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(avl_height(y->left), avl_height(y->right)) + 1;
    x->height = max(avl_height(x->left), avl_height(x->right)) + 1;

    return x;
}

AVLNode* avl_rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(avl_height(x->left), avl_height(x->right)) + 1;
    y->height = max(avl_height(y->left), avl_height(y->right)) + 1;

    return y;
}

AVLNode* avl_insert(AVLNode* root, Tanaman t) {
    if (!root) return avl_newNode(t);

    if (t.nama < root->data.nama)
        root->left = avl_insert(root->left, t);
    else if (t.nama > root->data.nama)
        root->right = avl_insert(root->right, t);
    else
        return root;

    root->height = 1 + max(avl_height(root->left), avl_height(root->right));

    int balance = avl_balance(root);

    // Left Left
    if (balance > 1 && t.nama < root->left->data.nama)
        return avl_rotateRight(root);

    // Right Right
    if (balance < -1 && t.nama > root->right->data.nama)
        return avl_rotateLeft(root);

    // Left Right
    if (balance > 1 && t.nama > root->left->data.nama) {
        root->left = avl_rotateLeft(root->left);
        return avl_rotateRight(root);
    }

    // Right Left
    if (balance < -1 && t.nama < root->right->data.nama) {
        root->right = avl_rotateRight(root->right);
        return avl_rotateLeft(root);
    }

    return root;
}

AVLNode* avl_findMin(AVLNode* node) {
    while (node->left) node = node->left;
    return node;
}

AVLNode* avl_delete(AVLNode* root, string nama) {
    if (!root) return NULL;

    if (nama < root->data.nama)
        root->left = avl_delete(root->left, nama);
    else if (nama > root->data.nama)
        root->right = avl_delete(root->right, nama);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } 
        else {
            AVLNode* temp = avl_findMin(root->right);
            root->data = temp->data;
            root->right = avl_delete(root->right, temp->data.nama);
        }
    }

    if (!root) return root;

    root->height = 1 + max(avl_height(root->left), avl_height(root->right));

    int balance = avl_balance(root);

    if (balance > 1 && avl_balance(root->left) >= 0)
        return avl_rotateRight(root);

    if (balance > 1 && avl_balance(root->left) < 0) {
        root->left = avl_rotateLeft(root->left);
        return avl_rotateRight(root);
    }

    if (balance < -1 && avl_balance(root->right) <= 0)
        return avl_rotateLeft(root);

    if (balance < -1 && avl_balance(root->right) > 0) {
        root->right = avl_rotateRight(root->right);
        return avl_rotateLeft(root);
    }

    return root;
}

// FIXED: avl_search now passes name on recursive calls
bool avl_search(AVLNode* root, string nama) {
    if (!root) return false;
    if (root->data.nama == nama) return true;

    if (nama < root->data.nama)
        return avl_search(root->left, nama);
    else
        return avl_search(root->right, nama);
}

void avl_print(AVLNode* node) {
    if (node) {
        avl_print(node->left);
        cout << "- " << node->data.nama << " [" << node->data.harga << "] h:" << node->height << "\n";
        avl_print(node->right);
    }
}

// ======================= DATA TANAMAN =========================

Tanaman tanaman[10] = {
    {"Peashooter", 100}, {"Sunflower", 50}, {"Repeater", 200},
    {"Cabbage", 100}, {"Jalapeno", 125}, {"Squash", 50},
    {"Lily", 25}, {"Sunshroom", 25}, {"Doom", 125}, {"Wallnut", 50}
};

void showPlants() {
    cout << "\nDaftar Tanaman:\n";
    for (int i = 0; i < 10; i++)
        cout << i+1 << ". " << tanaman[i].nama << " [" << tanaman[i].harga << "]\n";
}

// ======================= INTERACTIVE HELPERS =========================
void doBSTInsert(BSTNode*& bst) {
    showPlants();
    cout << "Pilih tanaman (1-10): ";
    int idx; cin >> idx;
    if (idx >= 1 && idx <= 10) {
        bst = bst_insert(bst, tanaman[idx-1]);
        cout << "Ditambahkan ke BST!\n";
    } else cout << "Pilihan tidak valid.\n";
}

void doAVLInsert(AVLNode*& avl) {
    showPlants();
    cout << "Pilih tanaman (1-10): ";
    int idx; cin >> idx;
    if (idx >= 1 && idx <= 10) {
        avl = avl_insert(avl, tanaman[idx-1]);
        cout << "Ditambahkan ke AVL!\n";
    } else cout << "Pilihan tidak valid.\n";
}

void doBSTDelete(BSTNode*& bst) {
    cout << "Nama tanaman: ";
    string nama; cin >> ws; getline(cin, nama);
    bst = bst_delete(bst, nama);
    cout << "Dihapus dari BST (jika ada)!\n";
}

void doAVLDelete(AVLNode*& avl) {
    cout << "Nama tanaman: ";
    string nama; cin >> ws; getline(cin, nama);
    avl = avl_delete(avl, nama);
    cout << "Dihapus dari AVL (jika ada)!\n";
}

void doBSTSearch(BSTNode* bst) {
    cout << "Nama tanaman: ";
    string nama; cin >> ws; getline(cin, nama);
    cout << (bst_search(bst, nama) ? "Ditemukan!\n" : "Tidak ditemukan!\n");
}

void doAVLSearch(AVLNode* avl) {
    cout << "Nama tanaman: ";
    string nama; cin >> ws; getline(cin, nama);
    cout << (avl_search(avl, nama) ? "Ditemukan!\n" : "Tidak ditemukan!\n");
}

// ======================= MAIN PROGRAM =========================
int main() {
    BSTNode* bst = NULL;
    AVLNode* avl = NULL;
    int choice;

    // initial
    bst = bst_insert(bst, tanaman[0]);
    bst = bst_insert(bst, tanaman[1]);
    avl = avl_insert(avl, tanaman[0]);
    avl = avl_insert(avl, tanaman[1]);

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. BST Insert\n2. BST Delete\n3. BST Search\n4. BST View\n";
        cout << "5. AVL Insert\n6. AVL Delete\n7. AVL Search\n8. AVL View\n";
        cout << "9. Show All Plants\n0. Exit\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1: doBSTInsert(bst); break;
            case 2: doBSTDelete(bst); break;
            case 3: doBSTSearch(bst); break;
            case 4:
                if (!bst) cout << "BST kosong!\n";
                else bst_print(bst);
                break;

            case 5: doAVLInsert(avl); break;
            case 6: doAVLDelete(avl); break;
            case 7: doAVLSearch(avl); break;
            case 8:
                if (!avl) cout << "AVL kosong!\n";
                else avl_print(avl);
                break;

            case 9: showPlants(); break;
            case 0: break;
            default: cout << "Pilihan tidak dikenal. Coba lagi.\n"; break;
        }

    } while (choice != 0);

    cout << "Program selesai!\n";
    return 0;
}
