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


    if(!data){
        fprintf(stderr, "Failed To Open a File\n");
        return EXIT_FAILURE;
    }

    system("cls");
    int n = 2;
    struct dataPemilih user[n];

    pilihanMenuAdmin(user[0].nama, user[0].kelas, user[0].NIM, user[0].JK, data, read);

    fclose(data);
    fclose(read);


}

