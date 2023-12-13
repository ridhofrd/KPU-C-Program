#include "menu.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>


void gotoxy(int x, int y) {
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int loginAwal(){

	int input;
	system("cls");
	char terminate;


	gotoxy(30,2); printf("                     SELAMAT DATANG                         \n");
	gotoxy(30,3); printf("                           DI                               \n");
    gotoxy(30,4); printf("                E-VOTE KPU HIMAKOM POLBAN                 \n\n");
    gotoxy(30,5); printf("               ===========================                   \n\n");
    gotoxy(30,7);printf("                1. MASUK                             \n");
    gotoxy(30,8);printf("                2. MASUK SEBAGAI ADMIN                            \n");


    gotoxy(30,11); printf("          PILIHAN	: ");
    scanf("%d", &input);
    scanf("%c", &terminate);

    switch(input){
		case 1:
            return 1;
			break;

		case 2:
            return 2;
			break;

		case 0:
            return 0;
			break;
	}
}



int reDo(){
    char statC, terminate;
    int stat = 0;
    printf("Apakah anda ingin kembali ke-menu utama?(y/n)");
    scanf("%c", &statC);
    scanf("%c", &terminate);
    if(statC == 'y' || statC == 'Y')
        stat = 1;


    return stat;
}
