#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include <windows.h>
#include <time.h>
#include <math.h>
//#include <date.h>

int main()
{
    FILE *data = fopen("data.txt", "a");
    FILE *read = fopen("data.txt", "r");
    int menu, lines = readRecordSize(read);


    if(!data){
        fprintf(stderr, "Failed To Open a File\n");
        return EXIT_FAILURE;
    }

    system("cls");
    int n = 2, stats = 1;
    struct dataPemilih user[n];


    while(stats == 1)
    {
        menu = pilihanMenuAdmin();
        if(menu == 1){
            inputDataAdmin(user[0].nama, user[0].kelas, user[0].NIM, user[0].JK, data, read);
            stats = reDo();
        }
        else if(menu == 2){
            lihatHasilSementara();
            stats = reDo();
        }
        else if(menu == 3){
            lihatUser();
            stats = reDo();

        }
        else{
            return 0;
        }
    }

    fclose(data);
    fclose(read);
}

