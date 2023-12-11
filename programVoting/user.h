#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

#ifndef user_h
#define user_h


int logIn(char *NIMIn[20]);
int vote(FILE *writeVote, FILE *backupVote);
int pilihanMenuUser();
void tampilkanVisiMisi();
void tampilkanIdentitasDiri(FILE *readUserIdentity, char NIMLog[20]);
void votingCalon();

#endif
