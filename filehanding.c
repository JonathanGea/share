#include <stdio.h>


int main()
{
    int cho;
    char name[50];
    int marks, i, num;
    int isi = 0;
    int jmlhMhs = 0;

    do
    {
        printf("Menu \n1. tambah data \n2. lihat data \n2. keluar \n\nmasukan pilihan anda : ");
        scanf("%d",&cho);
        switch (cho)
        {
        case 1:
            printf("Masukan Jumlah Mahasiswa: ");
            scanf("%d", &num);
            FILE *fptr;
            fptr = (fopen("student.txt", "a"));
            if(fptr == NULL)
            {
                printf("Error!");
                exit(1);
            }
            isi = 0;
            for(i = 0; i < num; ++i)
            {
                printf("Mahasiswa ke - %d\nNama: ", i+1);
                scanf("%s", name);

                printf("NIM : ");
                scanf("%d", &marks);

                fprintf(fptr,"Nama  : %s \nNIM  : %d \n", name, marks);
                isi++;
            }

            fclose(fptr);
            break;
        case 2:
            //ambil jmlhMhs
            //printf("sebelum dimasukan : %d\n", jmlhMhs);
            fptr = fopen("jlhSiswa.txt", "r");
            fscanf(fptr,"%d",&jmlhMhs);
            //<!--printf("%d", jmlhMhs);
            fclose(fptr);
            //printf("setelah dimasukan : %d\n", jmlhMhs);
            jmlhMhs = jmlhMhs + isi; // tambah dengan isi
            //printf("setelah ditambah : %d\n", jmlhMhs);
            // masukan jmlhmhs
            fptr = fopen("jlhSiswa.txt", "w");
            fprintf(fptr,"%d",jmlhMhs);
            fclose(fptr);



            printf("daftar mahasiswa : \n");

            fptr = fopen("student.txt", "r");
            char temp[200];
            for (int i = 0; i < (jmlhMhs*2); i++)
            {
                fgets(temp,300,fptr);
                printf("%s", temp);
            }
            fclose(fptr);

            break;
        case 3:
            exit(0);
            break;
        }
    }while(cho !=3);

        return 0;
}
