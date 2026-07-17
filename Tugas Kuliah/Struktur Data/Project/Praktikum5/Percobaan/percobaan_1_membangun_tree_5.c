// 24081010297 Hafidz Ali Murtadho
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree*pohon;

// Deklarasi dari tree dengan  menggunakan linked list
struct tree{
    char info;
    pohon kiri;
    pohon kanan;
};

/*Fungsi unutk membuat simpul yang pertama*/
pohon baru(char hrf) {
    pohon br;
    br = (pohon)malloc(sizeof(struct tree));
    br->info = hrf;
    br->kiri = NULL;
    br->kanan = NULL;
    return br;
}
/*Fungsi untuk menyisipkan simpul pada tree yang sudah dibangun*/
void sisip(pohon ph, pohon sp) {
    pohon P, Q;
    P = ph;
    Q = ph;
    while ((Q != NULL) && (sp->info != P->info)) {
        P = Q;
        if (sp->info < P->info)
            Q = P->kiri;
        else
            Q = P->kanan;
    }
    if (sp->info == P->info) {
        printf("Sudah ada\n");
    } else if (sp->info < P->info) {
        P->kiri = sp;
    } else {
        P->kanan = sp;
    }
}
/*Fungsi-fungsi untuk metode traversal secara rekurs*/
void preorder(pohon ph) {
    if (ph != NULL) {
        printf("%c ", ph->info);
        preorder(ph->kiri);
        preorder(ph->kanan);
    }
}
void inorder(pohon ph) {
    if (ph != NULL) {
        inorder(ph->kiri);
        printf("%c ", ph->info);
        inorder(ph->kanan);
    }
}
void postorder(pohon ph) {
    if (ph != NULL) {
        postorder(ph->kiri);
        postorder(ph->kanan);
        printf("%c ", ph->info);
    }
}

int main() {
    int j = 0;
    char input;
    char jawab[2];
    pohon br, ssp;
    
    while (1) {
        printf("Ketikkan huruf: ");
        scanf(" %c", &input); // Added space before %c to consume newline
        if (j == 0) {
        br = baru(input);
        } else {
            ssp = baru(input);
            sisip(br, ssp);
        }
        printf("Ada data lagi (y/t): ");
        scanf("%s", jawab);
        if (strcmp(jawab, "Y") == 0 || strcmp(jawab, "y") == 0) 
        {j++; continue;} 
        else if (strcmp(jawab, "T") == 0 || strcmp(jawab, "t") == 0) 
        {break;}
    }
    printf("\nPreorder traversal:\n");
    preorder(br);
    printf("\n");
    printf("\nInorder traversal:\n");
    inorder(br);
    printf("\n");
    printf("\nPostorder traversal:\n");
    postorder(br);
    printf("\n");
    return 0;
}
