#ifndef admin.h
#define admin.h
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

struct dataPemilih{
    char nama[100];
    char NIM[20];
    char kelas[10];
    char JK[2];
    char password[20];
};



int pilihanMenuAdmin();
void inputDataAdmin(char namaBaru[100], char NIMBaru[20], char kelasBaru[10], char JKBaru[2], FILE *dataFile, FILE *readFile);

void inputUser();

int reDo();

void lihatUser();


void lihatHasilSementara();


#endif
