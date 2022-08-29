#ifndef shuffle_INCLUDED
#define shuffle_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct baralho {
  char cartas[3];
  struct baralho *next;
} baralhos;

typedef struct modos {
  char num[2];
  struct modos *next;
} modo;
baralhos *cria_carta(FILE *, char *);
baralhos *insere_carta(baralhos *, baralhos *);
baralhos *shuffle1(baralhos *);
baralhos *shuffle2();
baralhos *shuffle3(baralhos *);
baralhos *shuffle(int,char *[],char*, char*, char*);
modo *insere_int(modo *, modo *);
modo *cria_int(FILE *, char *);
void print_cartas(baralhos *);
void print_inteiros(modo *);
void free_baralho(baralhos *);

#endif
