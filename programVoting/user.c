#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include "user.h"
#include "menu.h"
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void loading(){
	system("cls");
    system("color F1");

		gotoxy(30,9); printf("              =======================");
		gotoxy(30,10);printf("               MOHON TUNGGU SEBENTAR");
		gotoxy(30,12);printf("              =======================");

		Sleep(500);
		gotoxy(30,11);printf("                     . ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
}

int logIn(char *NIMIn[20]){
    system("cls");
    FILE *readIn = fopen("data.txt", "r");
    char passwordIn[20];
    char tempUsername[100], tempNIM[20], tempJK[2], tempKelas[10], tempPassword[20], tempStatus[2];
    int finalS = 0, i = 0;
    char terminate;

    printf("===============User Login=================\n\n");

    printf("Masukan NIM: ");
    scanf("%s", &*NIMIn);
    printf("Masukkan Password: ");
    scanf("%s", &passwordIn);
    scanf("%c", &terminate);

    printf("NIM:  %s\n", NIMIn);

    rewind(readIn);

    while(!feof(readIn)){
        fscanf(readIn, "%s %s %s %s %s %s", tempUsername, tempNIM, tempKelas, tempJK, tempPassword, tempStatus);
		if(strcmp(NIMIn, tempNIM) == 0){
            while(i < 4)
            {
                if(strcmp(passwordIn, tempPassword) == 0    ){
                    printf("Anda Berhasil Login!\n");
                    i = 4;
					return 1;
                }
                else{
                    if(i != 3){
                        printf("Password asli: %s\n", tempPassword);
                        printf("Password Salah! Silahkan Masukan Kembali Password\n");
                        printf("Password: ");
                        scanf("%s", &passwordIn);
                    }
                    else
                    {
                        printf("Sudah 3 Kali Salah!\n");
						return 2;
					}
                    i++;
                }
            }
        }
		finalS = 3;
    }
    if(feof(readIn))
    {
        printf("Proses Login Selesai\n");
        fclose(readIn);
    }

    return finalS;
}


int vote(FILE *writeVote, FILE *backupVote){
    char NIMIn[20], passIn[20];

    printf("==============HALAMAN UNTUK VOTING==============");
}


int pilihanMenuUser(){
    int key = 1, status = 1;
    int selectedOption = 1, submenuOption = 0;

    while(status == 1)
    {
        do {
            system("cls");
            printf("=================User Interface=================\n");
                // display the main menu
                printf("Pilih Menu:\n");
                printf("[%c]Lihat Visi Misi Calon\n", (selectedOption == 1) ? 'x' : ' ');
                printf("[%c]Lihat Identitas Diri\n", (selectedOption == 2) ? 'x' : ' ');
                printf("[%c]Lakukan Voting\n", (selectedOption == 3) ?'x' : ' ');
                printf("[%c]Logut dan Kembali ke Menu Utama\n", (selectedOption == 4) ? 'x' : ' ');
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
    }

            // Clear the console screen (for Windows) - Moved outside of the submenu loop
            // system("cls");

        if (submenuOption == 0) {
            printf("Exiting...\n");
        }

        return selectedOption;
    }

void tampilkanVisiMisi(){
    printf("================Halaman Visi Misi Calon=============\n\n");
    printf("Calon 1\n");
    printf("Nama: Farrel Keiza\n");
    printf("NIM: 2512312323\n");
    printf("Kelas: D3-2B\n");
    printf("Visi: Terwujudnya anggota HIMAKOM POLBAN yang semakin berprestasi dan kolaboratif sesuai minat bakatnya, memiliki rasa kekeluargaan, dan berjiwa sosial yang tinggi.\n");
    printf("Misi: Hihihihihihi\n\n");

    printf("Calon 2\n");
    printf("Nama: Banteng Hari Santoso\n");
    printf("NIM: 23452413123\n");
    printf("Kelas: D3-2C\n");
    printf("Visi: Huhuhuhuhuhu\n");
    printf("Misi: hehehehheheh\n");
}

void tampilkanIdentitasDiri(FILE *readUserIdentity, char NIMLog[20], int statusVoting){
    char tempNama[100], tempNIM[20], tempKelas[10], tempJK[2], tempPassword[20], tempStatus[2];
	char terminate;

	rewind(readUserIdentity);

    printf("================Identitas Diri User=====================\n\n");
    NIMLog[strcspn(NIMLog, " ")] = 0;
	printf("NIMLog: %s\n", NIMLog);

    while(!feof(readUserIdentity)){
        fscanf(readUserIdentity, "%s %s %s %s %s %s", tempNama, tempNIM, tempKelas, tempJK, tempPassword, tempStatus);
		if(strcmp(tempNIM,NIMLog) == 0 && statusVoting == 1){
            printf("Nama User: %s\n", tempNama);
            printf("Nama NIM: %s\n", tempNIM);
            printf("Kelas User: %s\n", tempKelas);
            printf("Jenis Kelamin: %s\n", tempJK);
            printf("Status: User masih bisa melakukan voting\n");
        }
        else if(strcmp(tempNIM, NIMLog) == 0 && statusVoting == 0){
            printf("Nama User: %s\n", tempNama);
            printf("Nama NIM: %s\n", tempNIM);
            printf("Kelas User: %s\n", tempKelas);
            printf("Jenis Kelamin: %s\n", tempJK);
            printf("Status: User sudah tidak bisa melakukan voting\n");
		}
    }


}

void votingCalon(char userNIM[20], int *permissionVote){
    FILE *readStream = fopen("dataCalon.txt", "r");
    int key = 1, tampilkanMenuVote = 1;
    int selectedOption = 1, submenuOption = 0;
    if(!readStream)
    {
        printf("Nothing to see here!");
    }

    while(tampilkanMenuVote == 1)
    {
        do {
            system("cls");


            printf("=================Menu Voting Calon=================\n");
                // display the main menu
                printf("Silahkan Untuk Melakukan Voting:\n");
                printf("[%c]Vote Calon Nomor Urut 1: Farrel Keiza\n", (selectedOption == 1) ? 'x' : ' ');
                printf("[%c]Vote Calon Nomor Urut 2: Banteng Hari Santoso\n", (selectedOption == 2) ? 'x' : ' ');
                printf("[%c]Exit\n", (selectedOption == 3) ? 'x' : ' ');

                key = getch();
                // Handle arrow key input for the main menu
                switch (key) {
                    case 72:  // Up arrow key
                        selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                        system("cls");
                        break;
                    case 80:  // Down arrow key
                        selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                        system("cls");
                        break;
                    case 13:  // Enter key
                        key = 13;
                        break;
                    default:
                        // Ignore other keys
                        break;
                }
            }while (key != 13);  // 13 is the ASCII code for Enter key

            if(selectedOption == 3)
            {
            	tampilkanMenuVote = 0;
            	break;
			}

            char conT, terminate1, terminate2;
            printf("Apakah anda yakin ingin memilih calon nomor urut %d (y/n)", selectedOption);
            scanf("%c%c", &conT, &terminate1);

            if(conT == 'y' || conT == 'Y'){
                char destination[20];
                selectedOption == 1 ? strcpy(destination, "Calon1") : strcpy(destination, "Calon2");
                printf("Terimakasih Anda Telah Melakukan Voting Terhadap Calon Nomor Urut %d\n", selectedOption);
                tampilkanMenuVote = 0;

                FILE *writeHasilVote = fopen("dataCalonWrite.txt", "w");
   				FILE *blacklistAppend = fopen("blackList.txt", "a");

				fprintf(blacklistAppend, "%s\n", userNIM);

				fclose(blacklistAppend);

                int i = 0;

                while(i < 2){
                    char state[20];
                    int jumlahVoting;
                    fscanf(readStream, "%s %d", state, &jumlahVoting);
                    if(strcmp(destination, state) == 0){
                        jumlahVoting++;
                        fprintf(writeHasilVote, "%s %d\n", state, jumlahVoting);
                    }
                    else{
                        fprintf(writeHasilVote, "%s %d\n", state, jumlahVoting);
                    }
                    i++;
                }
                if(feof(readStream))
                {
                    printf("Voting Telah Selesai Terimakasih!\n");
                    tampilkanMenuVote = 0;
                }

                fclose(writeHasilVote);

                *permissionVote = 0;

            }
            else{
                key = 1;
                tampilkanMenuVote = 1;
            }

    }


    fclose(readStream);
    FILE *writeStream = fopen("dataCalon.txt", "w");
    FILE *readMenuVote = fopen("dataCalonWrite.txt", "r");
    int i = 0;
    while(i < 2){
        char stateS[20];
        int jumlahVotingS;

        fscanf(readMenuVote, "%s %d", stateS, &jumlahVotingS);
        fprintf(writeStream, "%s %d\n", stateS, jumlahVotingS);
        i++;

    }

    fclose(writeStream);
    fclose(readMenuVote);
            // Clear the console screen (for Windows) - Moved outside of the submenu loop
            // system("cls");

    printf("Exiting....\n");
}

int statusUserAsk(){
    int status = 0;
        printf("Apakah anda ingin kembali ke menu user?(y/n)");
        char terminate, statusC;
        scanf("%c%c", &statusC, &terminate);
        if(statusC == 'y' || statusC == 'Y')
            status = 1;
        else
            status = 0;

    return status;
}

int validateVote(char NIMtoVal[20]){
	FILE *blacklist = fopen("blackList.txt", "r");
	int permission = 1;
	char NIMtemp[20];

	while(!feof(blacklist)){
		fscanf(blacklist, "%s", NIMtemp);
		if(strcmp(NIMtemp, NIMtoVal) == 0){
			printf("Maaf anda sudah tidak memiliki kuota voting!\n");
			permission = 0;
		}
		else
			continue;

		printf("Blacked NIM: %s\n", NIMtemp);
	}

	fclose(blacklist);
	return permission;
}
