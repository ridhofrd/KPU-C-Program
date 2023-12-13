#ifndef admin_h
#define admin_h

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

struct dataPemilih{
    char nama[100];
    char NIM[20];
    char kelas[10];
    char JK[2];
    char password[20];
    char statusVoting[2];
};



int pilihanMenuAdmin();
void inputDataAdmin(char namaBaru[100], char NIMBaru[20], char kelasBaru[10], char JKBaru[2], char statusVoting[2], FILE *dataFile, FILE *readFile);

void inputUser();

void lihatUser();

void lihatHasilSementara();

#endif
