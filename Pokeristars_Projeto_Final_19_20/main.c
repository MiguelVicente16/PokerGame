#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "Linha_Comando.h"
#include "Modos_d.h"
#include "shuffle.h"

int VerificaHand[10] = {0};
int Royal[5] = {0};                                                               // Este vetor e os seguintes ir�o guardar a posi��o das cartas que comp�em o tipo de m�o identificado.
int Flush[5] = {0};
int FourKind[4] = {0};
int Pair[7] = {0};
int Trio[7] = {0};
int Straight[5] = {0};
int StraightFlush[5] = {0};
int result = 0;
int write_file = 0;
int In_Game[9] = {0};
int  Player[9] = {1,1,1,1,1,1,1,1,1};                                             // Este vetor serve para guardar os jogadores ativos no modo dx. Inicialmente estao todos ativos.
int empates[9] = {0};
FILE *write;
int Restricoes (int , char*[]);
int WriteFile (char**, int, char*, char*, char*);

int main (int argc, char *argv[]){
  char *c_Faces;
  char *c_Rank;
  char *baralho;
  int max_B = 104;
  int Faces[14] = {0};
  int size = 0, mode = 0;
  int winner = 0;
  size = 14;
  c_Faces = (char*)malloc(size*sizeof(char));
  c_Rank = (char*)malloc(size*sizeof(char));
  baralho = (char*)malloc(max_B*sizeof(char));
  mode = VerificaModo(argv);
  write_file = WriteFile(argv, argc, baralho, c_Faces, c_Rank);
  if (mode == 1){
    argc = argc-2;                              // Dar o valor � vari�vel argc do n�mero de cartas inseridas.
    Copia_argv(argc, argv, c_Faces, c_Rank);
    if (Restricoes(argc, argv) == (-1))
    {
      printf("-1\n");
      free(baralho);
      free (c_Faces);
      free(c_Rank);
      return 0;
    }
  }
  else if (mode == 2)
  {
    Mode_d_i(argv, baralho, argc, c_Faces, c_Rank, Faces, mode);
    if (write_file == 1)
    {
      fclose(write);
    }
    free (c_Faces);
    free(c_Rank);
    return 0;
  }
  if(mode == 1){
    ConverteFaces(argc, Faces, c_Faces, c_Rank);
    switch (argc)
    {
      case 5:
      CincoCartas(argc, Faces,c_Faces, c_Rank);
      break;
      case 10:
      DezCartas ( argc, Faces,c_Faces, c_Rank, mode);
      break;
      case 7:
      SeteCartas (argc, Faces,c_Faces, c_Rank, mode, winner);
      break;
      case 9:
      NoveCartas (argc, Faces,c_Faces, c_Rank, mode);
      break;
      default:
      break;
    }
  }
  if (argv[1][0] == '-' && argv[1][1] == 's' && argv[1][2] == '1')
  {
    shuffle(argc, argv, baralho, c_Faces, c_Rank);
    fclose(write);
  }
  free(baralho);
  free (c_Faces);
  free(c_Rank);
  return 0;
}
//------------------------------------------------------------------Restricoes---------------------------------------------------------------------------//
int Restricoes (int argc, char *argv[]){
  int i=2, n=0, j=0, v=0, check = -1;
  char naipe[4] = {'C', 'E', 'O', 'P'};
  char valor[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
  if (argv[1][0] != '-' || argv[1][1] != 'c' || strlen(argv[1]) != 2)                     // Verifica se o porgrama � chamado com o modo -c.
  {
    return check;
  }
  switch (argc)
  {
    case 10:
    case 9:
    case 7:
    case 5:
    for (i = 2; i <= argc+1; i++)
    {
      if (argv[i][2] != '\0' || argv[i][1] == '\0')                                   // Verifica se o comprimento de cada carta for diferente de 2.
      {
        return check;
      }

      for (j=i+1; j <= argc+1 && argc != 10; j++){                                     // Verifica que no caso de 5,7 ou 9 cartas nao ha cartas repetidas.
        if (strcmp(argv[i],argv[j]) == 0)
        {
          return check;
        }
      }
      if (i<6 && argc == 10)                                                          // Verifica que no caso de 10 cartas n�o ha repetidas nas 5 primeiras.
      {
        for (j= i+1; j<=6; j++)
        {
          if (strcmp(argv[i],argv[j]) == 0)
          {
            return check;
          }
        }
      }
      if (i>6 && argc == 10)                                                          // Verifica que no caso de 10 cartas n�o ha repetidas nas 5 ultimas.
      {
        for (j= i+1; j<=11; j++)
        {
          if (strcmp(argv[i],argv[j]) == 0)
          {
            return check;
          }
        }
      }
      n=0;
      while (argv[i][1] != naipe[n] && n<=2)         // Verifica se s� usam os nipes admitidos
      {
        n++;
      }
      if (argv[i][1] != (naipe[n]))
      {
        return check;
      }
      v=0;
      while (argv[i][0] != valor[v] && v<=11)         // Verifica se s� usam os valores admitidos
      {
        v++;
      }
      if (argv[i][0] != valor[v])
      {
        return check;
      }
    }
    break;
    default:
    return check;
    break;
  }
  check = 0;
  return check;
}
// -----------------------------------------------------------------Restricoes_End---------------------------------------------------------------------------//
int WriteFile (char**argv, int argc, char*baralho, char *c_Faces, char *c_Rank){

  // Esta funçao verifica o programa irá escrever o resultado em ficheiro ou em stdout.

  int w_file = 0;
  if (argc >3)
  {
    if (argv[3][0]== '-' && argv[3][1]== 'o' && argc >= 4){
      if (argc == 5)
      {
        write = fopen(argv[4], "w");
        w_file = 1;
        return w_file;
      }
    }
  }
  return w_file;
}
