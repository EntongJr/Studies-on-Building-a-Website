#include <stdio.h>

struct mahasiswa
{
    char nama[30];
    int umur;
    float ipk;
};

int main(){
    int i;
    int n;
    
    printf("Masukkan Jumlah Mahasiswa : ");
    scanf("%d", &n);
    struct mahasiswa mhs[n];

    for(i = 0; i < n; i++){
        printf("Mahasiswa Ke : %d", i+1);
        printf("\nMasukkan Nama Anda : ");
        scanf("%s", &mhs[i].nama);

        printf("Masukkan Umur Anda : ");
        scanf("%d", &mhs[i].umur);

        printf("Masukkan Ipk Anda : ");
        scanf("%g", &mhs[i].ipk);
    }
    printf("\n");
    printf("DATA MAHASISWA");
    for(i = 0; i < n; i++){
        printf("\nMahasiswa Ke : %d", i+1);
        printf("\nNama Anda : %s", mhs[i].nama);
        printf("\nUmur Anda : %d", mhs[i].umur);
        printf("\nIpk Anda : %g", mhs[i].ipk);
        printf("\n");
    }
    return 0;
}