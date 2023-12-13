#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "menu.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include "user.h"

int main()
{
    FILE *dataUser;
    dataUser = fopen("data.txt", "a");
    FILE *readUser;
    readUser= fopen("data.txt", "r");
    FILE *dataCalon;
    dataCalon = fopen("dataCalon.txt", "a");
    FILE *readCalon;
    readCalon = fopen("dataCalon.txt", "r");
    FILE *dataCalonBackup;
    dataCalonBackup = fopen("dataCalonBackup.txt", "a");
    int menuAdmin, lines = readRecordSize(readUser), berhasilLogin;


    if(!dataUser || !readUser || !dataCalon || !dataCalonBackup || !readCalon){
        fprintf(stderr, "Failed To Open a File\n");
        return EXIT_FAILURE;
    }

    int n = 2, stats = 1, statusUser = 1, statusRole;
    struct dataPemilih user[n];


    while(stats == 1)
    {
        loading();
        statusRole = loginAwal();
        if(statusRole == 2)
        {
            int statusAdminLogin = AdminlogIn();
            if(statusAdminLogin == 1)
            {
                menuAdmin = pilihanMenuAdmin();
                if(menuAdmin == 1){
                    inputDataAdmin(user[0].nama, user[0].kelas, user[0].NIM, user[0].JK, dataUser, readUser);
                    stats = reDo();
                }
                else if(menuAdmin == 2){
                    lihatHasilSementara();
                    stats = reDo();
                }
                else if(menuAdmin == 3){
                    lihatUser();
                    stats = reDo();

                }
                else if(menuAdmin == 4){
                    stats = reDo();
                }
            }
            else if(statusAdminLogin == 2)
            {
                printf("Anda gagal untuk melakukan login\n");
            }
            else if(statusAdminLogin == 3){
                printf("Anda gagal melakukan login karena NIM anda menunjukkan bahwa anda bukan admin!\n");
            }
            stats = reDo();
        }
        else if(statusRole == 1){
            char NIMlogIn[20];

            berhasilLogin = logIn(&NIMlogIn);

            if(berhasilLogin == 1){
                while(statusUser == 1)
                {
                    int userSelec = pilihanMenuUser();
                    if(userSelec == 1){
                        tampilkanVisiMisi();
                        statusUser = statusUserAsk();
                    }
                    else if(userSelec == 2){
                        tampilkanIdentitasDiri(readUser, NIMlogIn);
                        statusUser = statusUserAsk();
                    }
                    else if(userSelec == 3){
                        votingCalon();
                        statusUser = statusUserAsk();

                    }
                    else if(userSelec == 4){
                        return 0;
                    }
                }

            }
            else if(berhasilLogin == 2){

                printf("Anda gagal melakukan login\n");

            }
            else{
                printf("Anda gagal melakukan login karena NIM anda belum terdaftar sebagai user!\n");
            }

            stats = reDo();
        }
        else{
            return 0;
        }
    }

    fclose(dataUser);
    fclose(readUser);
}

