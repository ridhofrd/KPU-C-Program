#include "admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>


int readRecordSize(FILE *recordS){
      int ch = 0;
      int lines=0;

      if (recordS == NULL){
        printf("Nothing to see here!\n");
        return 0;
      }

      while ((ch = fgetc(recordS)) != EOF)
        {
          if (ch == '\n')
        lines++;
        }
      fclose(recordS);

      return lines;
}


int pilihanMenuAdmin(){
    int key = 1;
    int selectedOption = 1, submenuOption = 0;


    do {
        system("cls");
        printf("=================Admin Interface=================\n");
            // Display the main menu
            printf("Pilih Menu:\n");
            printf("[%c]Daftarkan User\n", (selectedOption == 1) ? 'x' : ' ');
            printf("[%c]Lihat Hasil Sementara\n", (selectedOption == 2) ? 'x' : ' ');
            printf("[%c]Lihat Daftar User\n", (selectedOption == 3) ?'x' : ' ');
            printf("[%c]Exit\n", (selectedOption == 4) ? 'x' : ' ');

            key = getch();
            // Handle arrow key input for the main menu
            switch (key) {
                case 72:  // Up arrow key
                    selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
                    system("cls");
                    break;
                case 80:  // Down arrow key
                    selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
                    system("cls");
                    break;
                case 13:  // Enter key
                    return selectedOption;
                    break;
                default:
                    // Ignore other keys
                    break;
            }
        }while (key != 13);  // 13 is the ASCII code for Enter key


        // Clear the console screen (for Windows) - Moved outside of the submenu loop
        // system("cls");

    if (submenuOption == 0) {
        printf("Exiting...\n");
    }

    return selectedOption;
}

void inputDataAdmin(char namaBaru[100], char NIMBaru[20], char kelasBaru[10], char JKBaru[2], FILE *dataFile, FILE *readFile){
            // Display the submenu

            int size = 12, iC = 0;
            char password[size];
            const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
            char enterState;
            printf("Silahkan Masukkan Data...\n");
            printf("Masukkan Nama Pemilih Baru:");
            fgets(namaBaru, 100, stdin);
            printf("Masukkan NIM Pemilih Baru:");
            fgets(NIMBaru, 20, stdin);
            printf("Masukkan Kelas Pemilih Baru(contoh D3-1A):");
            fgets(kelasBaru, 10, stdin);
            printf("Masukkan Jenis Kelamin Pemilih Baru(P/W):");
            fgets(JKBaru, 2, stdin);
            if (size) {
                    srand(time(NULL));
                    --size;
                    for (size_t n = 0; n < size; n++) {
                        int keyChar = rand() % (int) (sizeof charset - 1);
                        password[n] = charset[keyChar];
                    }
                    password[size] = '\0';
            }
            namaBaru[strcspn(namaBaru, "\n")] = 0;
            NIMBaru[strcspn(NIMBaru, "\n")] = 0;
            kelasBaru[strcspn(kelasBaru, "\n")] = 0;
            JKBaru[strcspn(JKBaru, "\n")] = 0;
            while(namaBaru[iC]){
                if(isspace(namaBaru[iC]))
                {
                    namaBaru[iC] = '_';
                    printf("Dude\n");
                }
                iC++;
            }

            system("cls");

            printf("\nNama yang diinputkan: %s\n", namaBaru);
            printf("NIM yang diinputkan: %s\n", NIMBaru);
            printf("Kelas yang diinputkan: %s\n", kelasBaru);
            printf("Jenis Kelamin yang diinputkan: %s\n\n", JKBaru);
            printf("Password yang tergenerasi untuk user NIM %s : %s\n\n", NIMBaru, password);
            fprintf(dataFile, "%s %s %s %s %s T\n", namaBaru, NIMBaru, kelasBaru, JKBaru, password);
            printf("Klik enter jika sudah selesai!");
            scanf("%c", &enterState);
        }


void lihatUser(){
    char passwordStatus, terminate;
    char showName[100], showNIM[20], showKelas[10], showJK[2], showPassword[20], status[2];
    int i = 0;

    FILE *readUser = fopen("data.txt", "r");
    rewind(readUser);

    printf("Apakah anda ingin melihat data user beserta dengan passwordnya?(y/n)");
    scanf("%c%c", &passwordStatus, &terminate);


    printf("Berikut merupakan user yang terdaftar: \n\n");
    while(!feof(readUser)){
        fscanf(readUser, "%s %s %s %s %s %s", showName, showNIM, showKelas, showJK, showPassword, status);
        if(passwordStatus == 'y' || passwordStatus == 'Y')
            printf("%s %s %s %s %s %s\n", showName, showNIM, showKelas, showJK, showPassword, status);
        else
            printf("%s %s %s %s\n", showName, showNIM, showKelas, showJK);

    }
    if(feof(readUser))
        printf("Semua data telah terbaca yey!\n");

}

int reDo(){
    char statC, terminate;
    int stat = 0;
    printf("Apakah anda ingin kembali ke-menu utama?(y/n)");
    scanf("%c", &statC);
    scanf("%c", &terminate);
    if(statC == 'y' || statC == 'Y')
        stat = 1;

    printf("%c", statC);

    return stat;
}

void lihatHasilSementara(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Berikut merupakan hasil dari pemilihan per-tanggal %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Calon 1: \nCalon 2: \n");
}

