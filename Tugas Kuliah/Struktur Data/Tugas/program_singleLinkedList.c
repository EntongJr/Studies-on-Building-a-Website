// Nama : Achmad Dimas Saktiawannur Rofiq
// NPM  : 24081010354
// Matkul : Struktur Data H 081

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* head2 = NULL;



// Insert di Awal
void insertAwal(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert di Akhir
void insertAkhir(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;  
    newNode->next = NULL;
    
    if (head == NULL){
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert Akhir Untuk list 2
void insertAkhir2(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head2 == NULL){
        head2 = newNode;
        return;
    }

    struct Node* temp = head2;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert di Tengah
void insertTengah(int value, int pos){
    if (pos == 1){
        insertAwal(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    struct Node* temp = head;
    for (int i = 1; i < pos -1 && temp != NULL;i++){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Posisi tidak valid\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete di Awal
void deleteAwal(){
    if (head == NULL){
        printf("List Kosong\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete di Akhir
void deleteAkhir(){
    if (head == NULL){
        printf("List Kosong\n");
        return;
    }
    if (head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete di Tengah
void deleteTengah(int pos){
    if (head == NULL){
        printf("List Kosong");
        return;
    }

    if (pos == 1){
        deleteAwal();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++){
        temp = temp->next;
    }
    if (temp->next == NULL){
        printf("Posisisi Tidak Tepat");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Create List
void createList(int n){
    int value;
    head = NULL;
    for (int i = 0; i < n;i++){
        printf("Masukkan Data ke - %d: ", i+1);
        scanf("%d", &value);
        insertAkhir(value);
    }
}

// Traversing (menampilkan data atau List)
void traversing(){
    struct Node* temp = head;
    if (temp == NULL){
        printf("List Kosong");
        return;
    }
    while (temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");    
}

// Searching Data
void searching(int key){
    struct Node* temp = head;
    int pos = 1;
    while(temp != NULL){
        if (temp->data == key){
            printf("Data %d di Temukan di Posisi %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Data %d tidak ditemukan di list\n", key);
}

// Concatenation
void concatenation(){
    if (head == NULL){
        head = head2;
    }else{
        struct Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head2;
    }
    head2 = NULL;
    printf("List Berhasil di Gabungkan\n");
}

int main(){
    int pilihan, pos, value;

    do{
        printf("\nSingle Linked List\n");
        printf("1. Create List\n");
        printf("2. Insert Awal\n");
        printf("3. Insert Tengah atau Posisi yang dipilih\n");
        printf("4. Insert Akhir\n");
        printf("5. Delete Awal\n");
        printf("6. Delete Tengah atau Posisi yang Dipilih\n");
        printf("7. Delete Akhir\n");
        printf("8. Display List\n");
        printf("9. Searching\n");
        printf("10.Concatenate List\n");
        printf("0. Keluar\n");
        printf("Pilih : ");
        scanf("%d", &pilihan);

        switch (pilihan){
            case 1: 
                printf("Masukkan Jumlah Data : ");
                scanf("%d", &pos);
                createList(pos);
                printf("Baik Data Sudah Masuk");
                break;
            case 2: 
                printf("Masukkan Nilai : ");
                scanf("%d", &value);
                insertAwal(value);
                printf("Baik Data Sudah Masuk");
                break;
            case 3: 
                printf("Masukkan Nilai : ");
                scanf("%d", &value);
                printf("Masukkan Posisi : ");
                scanf("%d", &pos);
                insertTengah(value, pos);
                printf("Baik Data Sudah Masuk");
                break;
            case 4: 
                printf("Masukkan Nilai : ");
                scanf("%d", &value);
                insertAkhir(value);
                printf("Baik Data Sudah Masuk");
                break;
            case 5: 
                deleteAwal();
                printf("Data Awal Di Hapus");
                break;
            case 6: 
                printf("Masukkan Posisi yang Ingin di Hapus : ");
                scanf("%d", &pos);
                deleteTengah(pos);
                printf("Data Sudah Terhapus");
                break;
            case 7: 
                deleteAkhir();
                printf("Data Terakhir Di Hapus");
                break;
            case 8:
                traversing();
                break;
            case 9:
                printf("Masukkan Nilai yang Ingin di Cari : ");
                scanf("%d", &value);
                searching(value);
                break;
            case 10: 
                printf("Masukkan Jumlah Data untuk List Kedua : ");
                scanf("%d", &pos);
                for (int i = 0; i < pos; i++){
                    printf("Masukkan Data ke %d: ", i+1);
                    scanf("%d", &value);
                    insertAkhir2(value);
                }
                concatenation();
                break;
            case 0:
                printf("Keluar Program");
                break;
            default:
                printf("Pilihan Tidak Valid");
        }
    }while (pilihan != 0);
    return 0;
}