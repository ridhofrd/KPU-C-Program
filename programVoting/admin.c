#include "admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>



int pilihanMenuAdmin(char namaBaru[100], char NIMBaru[20], char kelasBaru[10], char JKBaru[2], FILE *dataFile, FILE *readFile){
    int key;
    int selectedOption = 1, submenuOption = 0;
    int size = 12;
    char password[size];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";


    do {
        printf("=================Admin Interface=================\n");
        if (submenuOption == 0) {
            // Display the main menu
            printf("Pilih Menu:\n");
            printf("[%c]Daftarkan User\n", (selectedOption == 1) ? 'x' : ' ');
            printf("[%c]Lihat Hasil Sementara\n", (selectedOption == 2) ? 'x' : ' ');
            printf("[%c]Lihat Daftar User\n", (selectedOption == 3) ?'x' : ' ');
            printf("[%c]Exit\n", (selectedOption == 4) ? 'x' : ' ');
        }
        else if(submenuOption == 1){
            // Display the submenu
            char enterState;
            printf("Silahkan Masukkan Data...\n");
            printf("Masukkan Nama Pemilih Baru:");
            fgets(namaBaru, 100, stdin);
            printf("Masukkan NIM Pemilih Baru:");
            fgets(NIMBaru, 20, stdin);
            printf("Masukkan Kelas Pemilih Baru:");
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
            printf("\nNama yang diinputkan: %s\n", namaBaru);
            printf("NIM yang diinputkan: %s\n", NIMBaru);
            printf("Kelas yang diinputkan: %s\n", kelasBaru);
            printf("Jenis Kelamin yang diinputkan: %s\n\n", JKBaru);
            namaBaru[strcspn(namaBaru, "\n")] = 0;
            NIMBaru[strcspn(NIMBaru, "\n")] = 0;
            kelasBaru[strcspn(kelasBaru, "\n")] = 0;
            JKBaru[strcspn(JKBaru, "\n")] = 0;
            printf("Password yang tergenerasi untuk user NIM %s : %s\n\n", NIMBaru, password);
            fprintf(dataFile, "%s %s %s %s %s\n", namaBaru, NIMBaru, kelasBaru, JKBaru, password);
            printf("Klik enter jika sudah selesai!");
            scanf("%c", &enterState);
        }

        // Wait for key press without Enter
        key = getch();

        if (submenuOption == 0) {
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
                    if (selectedOption == 1) {
                        submenuOption = 1;  // Enter submenu for Start Game
                        selectedOption = 1;
                        system("cls");
                        key = 0;
                        // Note: Removed clearing the console screen here
                    }
                    else if (selectedOption == 2){
                        system("cls");
                        printf("Berikut merupakan hasil dari pemilihan sementara per tanggal-<tanggal>: \n");
                        printf("Calon1: <jumlah>\n");
                        printf("Calon-n: <jumlah>\n");
                        return 0;
                    }
                    else if(selectedOption == 3){
                        char buffer[255];
                        system("cls");
                        printf("Berikut adalah data user/pemilih: \n\n");

                        while(fgets(buffer, 255, readFile)) {
                            printf("%s\n", buffer);
                        }
                    }
                    else if (selectedOption == 4) {
                        printf("Exiting...\n");
                        return 0;
                    }
                    break;
                default:
                    // Ignore other keys
                    break;
            }
        }

        // Clear the console screen (for Windows) - Moved outside of the submenu loop
        // system("cls");

    } while (key != 13);  // 13 is the ASCII code for Enter key

    if (submenuOption == 0) {
        printf("Exiting...\n");
    }

    return 0;
}

void inputUser(){
    printf("Anda Akan Menginput Pemilih Baru, Silahkan Isi Data Dibawah Dengan Identitas Pemilih Baru Tersebut!\n");
    printf("Nama: \n");
    printf("NIM: \n");
    printf("Kelas: \n");
    printf("Jenis Kelamin(P/W): \n");

}

void lihatHasilSementara(){
    printf("Berikut Merupakan Hasil Pemilihan Sementara per tanggal <sekian>");
}

