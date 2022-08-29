#ifndef MAIN_INCLUDED
#define MAIN_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int VerificaHand[10];
int Royal[5];                                                               // Este vetor e os seguintes ir�o guardar a posi��o das cartas que comp�em o tipo de m�o identificado.
int Flush[5];
int FourKind[4];
int Pair[7];
int Trio[7];
int Straight[5];
int StraightFlush[5];
int result;
int write_file;
int In_Game[9];
int  Player[9];                                             // Este vetor serve para guardar os jogadores ativos no modo dx. Inicialmente estao todos ativos.
int empates[9];
FILE *write;
int main (int, char *[]);
int Restricoes (int , char*[]);
int WriteFile (char**, int, char*, char*, char*);

#endif
