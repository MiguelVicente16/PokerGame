#include "shuffle.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// -------------------------------------------- SHUFFLE STARTS HERE -------------------------------------------------
//------------------------------------------------- Main do Shuffle ----------------------------------------------------
baralhos *shuffle(int argc, char *argv[], char*baralho, char *c_Faces, char *c_Rank )
{
  // o seguinte código verifica as condições de entrada neste modo
  baralhos *ListHead = NULL, *NewCard;
  int i=0;
  char integer[2];
  char inteiro[3];
  modo *remover;
  modo *tipo, *HeadNum = NULL;
  const char lookfor = '.';
  char *point;
  FILE *f_baralhos;
  char *file_name = argv[2];
  point = strchr(argv[2], lookfor);
  if ((*(point+1) != 's') || (*(point+2) != 'h') || (*(point+3) != 'u') || (*(point+4) != 'f') || (*(point+5) != 'f') || (*(point+6) != 'l') || (*(point+7) != 'e'))
  {
    if (write_file == 1)
    {
      fprintf(write, "-1\n");
      fclose(write);
    } else
    {
      printf("-1\n");
    }
    exit(0);
  }
  f_baralhos = fopen(file_name, "r");
  if (f_baralhos == NULL)
  {
    if (write_file == 1)
    {
      fprintf(write, "-1\n");
      fclose(write);
    } else
    {
      printf("-1\n");
    }
    exit(0);
  }
  while (fscanf(f_baralhos, "%s", inteiro) != EOF)
  {
    HeadNum = NULL;
    ListHead = NULL;
    while (strlen(inteiro) == 1)
    {
      strncpy(integer,inteiro,1);
      integer[1] = '\0';
      tipo = cria_int(f_baralhos, integer);
      HeadNum = insere_int(HeadNum, tipo);
      if (fscanf(f_baralhos, "%s", inteiro) == EOF) {
        break;
      }
    }
    //criação da lista com as cartas
    i=0;
    for (i=0; i<52; i++)
    {
      NewCard = cria_carta(f_baralhos, inteiro);
      ListHead = insere_carta(ListHead, NewCard);
      if (i != 51)
      {
        if (fscanf(f_baralhos, "%s", inteiro) == EOF){
          break;
        }
      }
    }
    while (HeadNum != NULL)
    {
      if (*(HeadNum->num) == '1')
      {
        ListHead = shuffle1(ListHead);
      }
      else if (*(HeadNum->num) == '2')
      {
        ListHead = shuffle2(ListHead);
      }
      else if (*(HeadNum->num) == '3')
      {
        ListHead = shuffle3(ListHead);
      }
      remover = HeadNum;
      HeadNum = HeadNum->next;
      free(remover);
    }
    print_cartas(ListHead);
    free_baralho(ListHead);
  };
  fclose (f_baralhos);

  return ListHead;
}
//------------------------------------------------- Final da Main do Shuffle ----------------------------------------------------
//------------------------------------------------- Criar carta para lista ----------------------------------------------------
baralhos *cria_carta(FILE *f_baralhos, char *inteiro) // ir buscar a primeira carta para meter na lista
{
  baralhos *new_card;
  if ((new_card = (baralhos*) calloc(1, sizeof(baralhos))) == NULL)
  {
    printf("Falha na alocação da memória\n");
    free(new_card);
    exit(0);
  }
  sprintf(new_card->cartas,"%s", inteiro);
  new_card->next = NULL;
  return new_card;
}
//------------------------------------------------- Fim da Criar carta para lista ----------------------------------------------------

//------------------------------------------------- Criar inteiro para lista ----------------------------------------------------
modo *cria_int(FILE *f_baralhos, char *inteiro)
{
  modo *new_int;
  if ((new_int = (modo*) calloc(1, sizeof(modo))) == NULL)
  {
    printf("-1\n");
    free(new_int);
    exit(0);
  }
  sprintf(new_int->num,"%s", inteiro);
  new_int->next = NULL;
  return new_int;
}
//------------------------------------------------- Fim da Criar inteiro para lista ----------------------------------------------------

//------------------------------------------------- Inserir carta na lista ----------------------------------------------------
baralhos *insere_carta(baralhos *ListHead, baralhos *NewCard) // inserir cartas no final da lista
{
  baralhos *aux;
  if (ListHead == NULL)
  {
    ListHead = NewCard;
  }
  else
  {
    aux = ListHead;
    while (aux->next != NULL)
    {
      aux = aux->next;
    }
    aux->next = NewCard;
  }
  return ListHead;
}
//------------------------------------------------- Fim da Inserir carta na lista ----------------------------------------------------

//------------------------------------------------- Inserir inteiro na lista ----------------------------------------------------
modo *insere_int(modo *ListHead, modo *inteiro)
{
  modo *aux;
  if (ListHead == NULL)
  {
    ListHead = inteiro;
  }
  else
  {
    aux = ListHead;
    while (aux->next != NULL)
    {
      aux = aux->next;
    }
    aux->next = inteiro;
  }
  return ListHead;
}
//------------------------------------------------- Fim da Inserir inteiro na lista ----------------------------------------------------

//------------------------------------------------- Funções de baralhar ----------------------------------------------------
// o seguinte código faz o baralhamento da forma 1
baralhos *shuffle1(baralhos *ListHead)
{
  baralhos *middle = NULL;
  baralhos *last; // última da primeira metade
  baralhos *slow_ptr = ListHead; // avança de um em um
  baralhos *fast_ptr = ListHead; // avança de dois em dois
  baralhos *aux1;
  baralhos *aux2;
  baralhos *aux3;
  baralhos *stop;
  if (ListHead!=NULL)
  {
    // dois ponteiros vão avançando na lista, um de 2 em 2 e outro de 1 em 1. Quando o primeiro chegar ao final da lista, o segundo encontra-se na do centro
    while (fast_ptr->next->next != NULL)  // slow fica a apontar para a última carta da priemira mão
    {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
    }
    last = slow_ptr;
    middle = slow_ptr->next;
    stop = fast_ptr->next;
  }
  last->next = middle->next;
  aux2 = ListHead->next; // aponta para a 2ª carta do 1º baralho na primeira vez, ou seja, carta para onde a nova carta a inserir tem de ficar a apontar
  ListHead->next = middle; //
  middle->next = aux2;
  aux3 = middle->next;  // aponta para a carta que vai ficar a apontar para a que vem do 2º baralho
  do {
    aux2 = aux2->next;   // aponta para a carta para onde a nova carta a inserir tem de ficar a apontar
    aux1 = last->next;
    last->next = last->next->next;
    aux1->next = aux2;
    aux3->next = aux1;
    aux3 = aux3->next->next;
  } while(last->next != stop);
  return ListHead;
}

// o seguinte código faz o baralhamento da forma 2
baralhos *shuffle2 (baralhos *ListHead)
{
  baralhos *slow_ptr = ListHead; // avança de um em um
  baralhos *fast_ptr = ListHead; // avança de dois em dois
  baralhos *last; //última carta da primeira parte
  baralhos *aux1;
  if (ListHead != NULL)
  {
    // dois ponteiros vão avançando na lista, um de 2 em 2 e outro de 1 em 1. Quando o primeiro chegar ao final da lista, o segundo encontra-se na do centro
    while (fast_ptr->next->next != NULL)  // fast fica a apontar para a penultima de todas
    {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
    }
    int count = 1;
    while (count != 26)
    {
      last = fast_ptr->next;
      fast_ptr->next = NULL;
      aux1 = slow_ptr->next;
      slow_ptr->next = last; // slow é a carta que vai ter de apontar para a outra que vem do fim
      last->next = aux1;
      slow_ptr = slow_ptr->next;
      fast_ptr = ListHead;
      while (fast_ptr->next->next != NULL)  // fast fica a apontar para a penultima de todas
      {
        fast_ptr = fast_ptr->next->next;
      }
      count++;
    }
  }
  shuffle1(ListHead);
  return ListHead;
}

// o seguinte código faz o baralhamento da forma 3
baralhos *shuffle3(baralhos *ListHead)
{
  baralhos *last;  // última de todas as cartas
  baralhos *aux;
  baralhos *fast_ptr = ListHead; // avança de dois em dois
  int count = 0;
  do
  {
    while (fast_ptr->next->next != NULL)  // slow fica a apontar para a última carta da última mão
    {
      fast_ptr = fast_ptr->next->next;
    }
    last = fast_ptr->next;
    fast_ptr->next = NULL;
    aux = ListHead;
    ListHead = last;
    ListHead->next = aux;
    fast_ptr = ListHead;
    count++;
  } while (count != 26);
  return ListHead;
}

//------------------------------------------------- Fim das Funções de baralhar ----------------------------------------------------

//------------------------------------------------- Free das listas ----------------------------------------------------
void free_baralho(baralhos *ListHead)
{
  baralhos *aux;
  aux = ListHead;
  while (ListHead != NULL)
  {
    aux = ListHead;
    ListHead = ListHead->next;
    free(aux);
  }
}
//------------------------------------------------- Fim da Free das listas ----------------------------------------------------

//------------------------------------------------- Imprimir as listas --------------------------------------------------------
void print_cartas(baralhos *ListHead)
{
  baralhos *aux;
  int count=0;
  for (aux = ListHead; aux != NULL; aux = aux->next)
  {
    if (write_file == 1)
    {
      fprintf(write,"%s ", aux->cartas);
    } else
    {
      printf("%s ", aux->cartas);
    }
    count++;
    if (count == 13)
    {
      if (write_file == 1)
      {
        fprintf(write,"\n");
      } else
      {
        printf("\n");
      }
      count = 0;
    }
  }
  if (write_file == 1)
  {
    fprintf(write,"\n");
  } else
  {
    printf("\n");
  }
}
//------------------------------------------------- Fim de Imprimir as listas --------------------------------------------------------
