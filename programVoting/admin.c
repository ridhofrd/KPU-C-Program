#include "admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>


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
            printf("[%c]Kembali Ke Menu Utama\n", (selectedOption == 4) ? 'x' : ' ');
            printf("[%c]Exit\n", (selectedOption == 5) ? 'x' : ' ');

            key = getch();
            // Handle arrow key input for the main menu
            switch (key) {
                case 72:  // Up arrow key
                    selectedOption = (selectedOption > 1) ? selectedOption - 1 : 5;
                    system("cls");
                    break;
                case 80:  // Down arrow key
                    selectedOption = (selectedOption < 5) ? selectedOption + 1 : 1;
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
            // Display the submenu;

            if(!dataFile || !readFile){
                printf("Nothing to see here!\n");
                return 0;
            }

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

            fclose(dataFile);
            fclose(readFile);
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

void lihatHasilSementara(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char calon[20];
    int jumlah;

    FILE *hasilVote = fopen("dataCalon.txt", "r");

    printf("Berikut merupakan hasil dari pemilihan per-tanggal %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    while(!feof(hasilVote))
    {
        fscanf(hasilVote, "%s %d", calon, &jumlah);
        printf("%s: %d\n", calon, jumlah);
    }
    if(feof(hasilVote)){
        printf("Pembacaan hasil voting sudah selesai!\n");
    }

    fclose(hasilVote);
}

int AdminlogIn(){
    system("cls");
    FILE *readIn = fopen("dataAdmin.txt", "r");
    char passwordIn[20], NIMIn[20];
    char tempUsername[100], tempNIM[20], tempJK[2], tempKelas[10], tempPassword[20];
    int finalS = 0, i = 0;
    char terminate;

    printf("===============Admin Login=================\n\n");

    printf("Masukan NIM Admin: ");
    scanf("%s", &NIMIn);
    printf("Masukkan Password Admin: ");
    scanf("%s", &passwordIn);
    scanf("%c", &terminate);

    printf("NIM:  %s\n", NIMIn);

    rewind(readIn);

    while(!feof(readIn)){
        fscanf(readIn, "%s %s %s %s %s", tempUsername, tempNIM, tempKelas, tempJK, tempPassword);
        if(strcmp(NIMIn, tempNIM) == 0){
            while(i < 4)
            {
                if(strcmp(passwordIn, tempPassword) == 0    ){
                    printf("Anda Berhasil Login!\n");
                    finalS = 1;
                    return finalS;
                    i = 4;

                }
                else{
                    if(i != 3){
                        printf("Password Salah! Silahkan Masukan Kembali Password\n");
                        printf("Password: ");
                        scanf("%s", &passwordIn);
                    }
                    else
                    {
                        finalS = 2;
                        printf("Sudah 3 Kali Salah!\n");
                        return finalS;
                    }

                    i++;
                }
            }
        }
        finalS = 3;

    }
    if(feof(readIn))
    {
        printf("Proses Login Admin Selesai\n");
        fclose(readIn);
    }
    return finalS;


}

