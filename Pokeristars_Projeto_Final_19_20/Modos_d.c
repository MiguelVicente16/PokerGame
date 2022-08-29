#include "main.h"
#include "Modos_d.h"
#include "Linha_Comando.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int VerificaModo (char **argv){

  // Esta função é utilizada para verificar qual o modo de processamento do jogo (-c, -di, -dx)

  static int choose = 0;
  choose++;
  if (choose == 1)
  {
    if(argv[1][0] == '-' && argv[1][1] == 'c'){
      return 1;
    } else if (argv[1][0] == '-' && argv[1][1] == 'd')
    {
      return 2;
    }
  } else if (choose == 2) {
    if (argv[1][2]== 'x')
    {
      return 3;
    } else return 2;
  } else if (choose == 3)
  {
    if (argv[1][2] == '1')
    {
      return 5;
    } else if (argv[1][2] == '2')
    {
      return 7;
    } else if (argv[1][2] == '3')
    {
      return 9;
    } else if (argv[1][2] == '4')
    {
      return 10;
    }
  }
  return 0;
}

void Mode_d_i(char **argv, char *baralho, int argc, char *c_Faces, char*c_Rank, int Faces[], int mode){

  // Esta função apenas é chamada no modo di e dx.

  int max_B = 104;
  int i = 0;
  long int size = -1;
  int nr_baralhos = 0;
  int loop = 1;
  int time = 0;
  int winner = 0;
  FILE *file;
  char *file_name = argv[2];
  Restricoes2 (argv, argc, c_Faces, c_Rank, baralho);
  file = fopen(file_name, "r");
  if (file == NULL) {
    if (write_file == 1) {
      fclose(write);
    }
    fclose(file);
    free(baralho);
    free(c_Faces);
    free(c_Rank);
    exit(0);
  }
  while (fscanf( file, "%c", &baralho[i]) != EOF)
  {
    if (baralho[i] != ' ' && baralho[i] != '\n'  && baralho[i] != '\t')           // Leitura das cartas do ficheiro e inserção destas na malloc baralho.
    {
      i++;
    }
    if (i == max_B){
      max_B = max_B + 104;
      baralho = (char*)realloc(baralho,max_B);
    }
  }
  fclose(file);
  i = 0;
  if (max_B == 104) {                                                             // Caso o ficheiro apenas tenha um baralho, a variavel nr_baralhos fica com o valor 1;
    nr_baralhos = 1;
  } else{                                                                         // Caso o ficheiro tenha mais que um baralho, realiza o calculo de quantos foram inseridos.
    while (i != (max_B - 104))
    {
      size++;
      i++;
    }
    nr_baralhos = (size/104)+1;
  }
  mode = VerificaModo(argv);
  argc = VerificaModo(argv);
  if (mode == 2) {
    switch (argc)
    {
      case 5:
      Mode_d1(baralho, argc, Faces, c_Faces, c_Rank, nr_baralhos, argv);
      break;
      case 10:
      Mode_d4(baralho, argc, Faces, c_Faces, c_Rank, nr_baralhos, mode, argv);
      break;
      case 7:
      Mode_d2(baralho, argc, Faces, c_Faces, c_Rank, nr_baralhos, argv, mode);
      break;
      case 9:
      Mode_d3(baralho, argc, Faces, c_Faces, c_Rank, nr_baralhos, mode, argv);
      break;
      default:
      break;
    }
  } else if (mode == 3){
    Restricoes2 (argv, argc, c_Faces, c_Rank, baralho);
    while (loop <=  nr_baralhos) {
      ModeDx(baralho, nr_baralhos, argc, c_Faces, c_Rank, mode, Faces);
      loop++;
    }
    time = 2;
    Estatisticas_2(time, winner, empates);
  }
  free(baralho);
}

void Mode_d1(char* baralho ,int argc, int Faces[],char *c_Faces, char *c_Rank, int nr_baralhos, char **argv){

  // Cada baralho é processado em grupos de 5 cartas.
  // Caso sobrem cartas no baralho e nao seja possivel formar um grupo de 5, as cartas que sobram desse baralho sao desprezadas.
  // Depois de escolher o grupo de 5 cartas, identifica a mao presente nesse grupo e imprime a numero respetivo a essa mao como é feito no modo linha de comando.

  int i;
  int ciclo = 10;
  int face = 0;
  int rank = 1;
  int time = 0;
  while (nr_baralhos!= 0)
  {
    while (ciclo != 0)
    {
      for (i = 2; i <= argc+1; i++)
      {
        c_Faces[i] = baralho[face];
        c_Rank [i] = baralho[rank];
        face+=2;
        rank+=2;
      }
      Restricoes2 (argv, argc, c_Faces, c_Rank, baralho);
      if (result != -1)
      {
        ConverteFaces(argc, Faces, c_Faces, c_Rank);
        CincoCartas(argc, Faces,c_Faces, c_Rank);
        Estatisticas(time);
      }else
      {
        if (write_file == 1)
        {
          fprintf(write,"-1\n");
        }else
        {
          printf("-1\n");
        }
      }
      ciclo--;
    }
    if (write_file == 1)
    {
      fprintf(write,"\n");
    }else
    {
      printf("\n");
    }
    face+=4;
    rank+=4;
    nr_baralhos--;
    ciclo = 10;
  }
  time ++;
  Estatisticas(time);
}

void Mode_d2(char* baralho ,int argc, int Faces[],char *c_Faces, char *c_Rank, int nr_baralhos,char **argv, int mode){

  // Cada baralho é processado em grupos de 7 cartas.
  // Caso sobrem cartas no baralho e nao seja possivel formar um grupo de 7, as cartas que sobram desse baralho sao desprezadas.
  // Depois de escolher o grupo de 7 cartas, identifica a mao presente nesse grupo e imprime o numero e mao correspondente como é feito no modo linha de comando.

  int i;
  int ciclo = 7;
  int face = 0;
  int rank = 1;
  int time = 0;
  int winner = 0;
  while (nr_baralhos > 0)
  {
    while (ciclo != 0)
    {
      for (i = 2; i <= argc+1; i++)
      {
        c_Faces[i] = baralho[face];
        c_Rank [i] = baralho[rank];
        face+=2;
        rank+=2;
      }
      Restricoes2 (argv, argc, c_Faces, c_Rank, baralho);
      if (result != -1)
      {
        ConverteFaces(argc, Faces, c_Faces, c_Rank);
        SeteCartas(argc, Faces,c_Faces, c_Rank, mode, winner);
        Estatisticas(time);
      } else
      {
        if (write_file == 1)
        {
          fprintf(write,"-1\n");
        }else
        {
          printf("-1\n");
        }
      }
      ciclo--;
    }
    if (write_file == 1)
    {
      fprintf(write,"\n");
    }else
    {
      printf("\n");
    }
    face+=6;
    rank+=6;
    nr_baralhos--;
    ciclo = 7;
  }
  time ++;
  Estatisticas(time);
}

void Mode_d3(char* baralho ,int argc, int Faces[],char *c_Faces, char *c_Rank, int nr_baralhos, int mode, char **argv){

  // Cada baralho é processado em grupos de 9 cartas.
  // Caso sobrem cartas no baralho e nao seja possivel formar um grupo de 9, as cartas que sobram desse baralho sao desprezadas.
  // Depois de escolher o grupo de 9 cartas, identifica a mao presente e cada uma das maos nesse grupo e imprime o numero e mao correspondente e o o resultado de entre as duas maos como é feito no modo linha de comando.

  int i;
  int ciclo = 5;
  int face = 0;
  int rank = 1;
  int time = 0;
  while (nr_baralhos > 0)
  {
    while (ciclo != 0)
    {
      for (i = 2; i <= argc+1; i++)
      {
        c_Faces[i] = baralho[face];
        c_Rank [i] = baralho[rank];
        face+=2;
        rank+=2;
      }
      Restricoes2 (argv, argc, c_Faces, c_Rank, baralho);
      if (result != -1)
      {
        ConverteFaces(argc, Faces, c_Faces, c_Rank);
        NoveCartas(argc, Faces,c_Faces, c_Rank, mode);
      } else
      {
        time = 4;
        Estatisticas(time);
        if (write_file == 1)
        {
          fprintf(write,"-1\n");
        }else
        {
          printf("-1\n");
        }
      }
      time = 2;
      Estatisticas(time);
      ciclo--;
    }
    if (write_file == 1)
    {
      fprintf(write,"\n");
    }else
    {
      printf("\n");
    }
    face+=14;
    rank+=14;
    nr_baralhos--;
    ciclo = 5;
  }
  time = 1;
  Estatisticas(time);
}

void Mode_d4(char* baralho ,int argc, int Faces[],char *c_Faces, char *c_Rank, int nr_baralhos, int mode, char **argv){

  // Cada baralho é processado em grupos de 10 cartas.
  // Caso sobrem cartas no baralho e nao seja possivel formar um grupo de 10, as cartas que sobram desse baralho sao desprezadas.
  // Depois de escolher o grupo de 10 cartas, identifica a mao presente e cada uma das maos nesse grupo e imprime o numero e mao correspondente e o o resultado de entre as duas maos como é feito no modo linha de comando.

  int i;
  int ciclo = 5;
  int face = 0;
  int rank = 1;
  int time = 0;
  while (nr_baralhos > 0)
  {
    while (ciclo != 0)
    {
      for (i = 2; i <= argc+1; i++)
      {
        c_Faces[i] = baralho[face];
        c_Rank [i] = baralho[rank];
        face+=2;
        rank+=2;
      }
      Restricoes2 (argv, argc, c_Faces, c_Rank, baralho);
      ConverteFaces(argc, Faces, c_Faces, c_Rank);
      if (result != -2 || result != -3) {
        DezCartas(argc, Faces,c_Faces, c_Rank, mode);
        time = 2;
        Estatisticas(time);
      }
      ciclo--;
    }
    if (write_file == 1)
    {
      fprintf(write,"\n");
    }else
    {
      printf("\n");
    }
    face+=4;
    rank+=4;
    nr_baralhos--;
    ciclo = 5;
  }
  time = 0;
  time ++;
  Estatisticas(time);
}

void Estatisticas (int time){

  // Esta função realiza as Estatisticas do modo di em funçao do caso identificado (d(1,2,3 ou 4)).
  // É chamada varias vezes ao longo do codigo inclusivé na função Restricoes2 (para fazer a contagem do -1). É tambem chamada em cada modo di e nas funções DezCartas e NoveCartas
  // O que esta função realiza depende do valor da variavel time, que é passada como argumento, cada vez que é chamada.

  int PokerHand = 0;
  static double count = 0;
  int i = 0;
  static double count_type[11] = {0};
  static double statics[11] = {0};
  static int resultado[3] = {0};
  static int dez = 0;
  static int sair = 0;

  if (time == 0){
    count++;
    for (i = 0; i < 10; i++)
    {
      if (VerificaHand[i] != 0)
      {
        PokerHand = VerificaHand[i];
      }
    }
    switch (PokerHand)
    {
      case 1:
      count_type[1]++;
      break;
      case 2:
      count_type[2]++;
      break;
      case 3:
      count_type[3]++;
      break;
      case 4:
      count_type[4]++;
      break;
      case 5:
      count_type[5]++;
      break;
      case 6:
      count_type[6]++;
      break;
      case 7:
      count_type[7]++;
      break;
      case 8:
      count_type[8]++;
      break;
      case 9:
      count_type[9]++;
      break;
      case 10:
      count_type[10]++;
      break;
      default:
      break;
    }
  } else if (time == 1)
  {
    statics[0] = (double)(count_type[0]/count);
    if (write_file == 1)
    {
      fprintf(write,"-1 %.2E\n", statics[0]);
    } else
    {
      printf("-1 %.2E\n", statics[0]);
    }

    for ( i = 1; i < 11; i++)
    {
      statics[i] = (double)(count_type[i]/count);
      if (write_file == 1)
      {
        fprintf(write,"%d %.2E\n",i, statics[i]);
      } else
      {
        printf("%d %.2E\n",i, statics[i]);
      }
    }
  } else if (time == 2)
  {
    dez = 1;
    switch (result)
    {
      case 0:
      resultado[0]++;
      break;
      case 1:
      resultado[1]++;
      break;
      case 2:
      resultado[2]++;
      break;

      default:
      break;
    }
  } else if (time == 3)
  {
    if (result == -1 || result == -2 || result == -3)
    {
      count_type[0]++;
      if (sair == 0 && (result == -2 || result == -3) ) {
        count++;
        resultado[0]++;
      } else if (result == -1) {
        count++;
        resultado[0]++;
      }
      sair++;
    }
    if (sair >= 2) {
      sair = 0;
    }
  } else if (time == 4)
  {
    count_type[0]++;
    count++;
  }
  if ((dez == 1) && (time == 1))
  {
    if (write_file == 1)
    {
      fprintf(write,"\n");
      for ( i = 0; i <3; i++)
      {
        fprintf(write,"%d %d\n", i, resultado[i]);
      }
    } else
    {
      printf("\n");
      for ( i = 0; i <3; i++)
      {
        printf("%d %d\n", i, resultado[i]);
      }
    }
  }
}

void Restricoes2 (char **argv, int argc,char *c_Faces, char *c_Rank, char *baralho){

  // Esta função apenas é utilizada nos modos di e dx.
  // É inicialmente chamada na função di, no qual verifica se esta tudo correto em relação ao que é escrito na linha de comando.
  // As proximas vezes que for chamada, as verificaçoes que ira realizar dependem do modo onde foi chamada d(1, 2, 3 ou x). Esta segunda funcionalidade desta função tem como objetivo, identificar mãos ilegais.

  int i=0, j = 0, n = 0, v = 0;
  char naipe[4] = {'C', 'E', 'O', 'P'};
  char valor[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
  int time = 3;
  result = 0;
  const char lookfor = '.';
  char *point;
  static int times = 0;
  point = strrchr(argv[2], lookfor);
  // opçoes do que se mete diretamente no terminal
  if (times == 0) {
    if ((argc != 3) && (argc != 5)) {
      printf("-1\n");
      if (write_file == 1) {
        fclose(write);
      }
      free (baralho);
      free (c_Faces);
      free(c_Rank);
      exit(0);
    }
    if (argv[1][0] != '-' || strlen(argv[1]) != 3) {
      printf("-1\n");
      if (write_file == 1) {
        fclose(write);
      }
      free (baralho);
      free (c_Faces);
      free(c_Rank);
      exit(0);
    }
    if (argv[1][1] != 'd' || ((argv[1][1] == 'd') && (argv[1][2] != '1' && argv[1][2] != '2'&&  argv[1][2] != '3' &&  argv[1][2] != '4' && argv[1][2] != 'x'))){  // casos do modo d
      printf("-1\n");
      if (write_file == 1) {
        fclose(write);
      }
      free (baralho);
      free (c_Faces);
      free(c_Rank);
      exit(0);
    }
    if ((*(point+1) != 'd') || (*(point+2) != 'e') || (*(point+3) != 'c') || (*(point+4) != 'k') ||  (*(point+5) != '\0'))  // verificaçao se o ficheiro tem extensão .deck
    {
      printf("-1\n");
      if (write_file == 1) {
        fclose(write);
      }
      free (baralho);
      free (c_Faces);
      free(c_Rank);
      exit(0);
    }
    if (argc == 5) {
      if (strcmp(argv[3], "-o") != 0) {
        printf("-1\n");
        if (write_file == 1) {
          fclose(write);
        }
        free (baralho);
        free (c_Faces);
        free(c_Rank);
        exit(0);
      }
      point = strrchr(argv[4], lookfor);
      if (point == NULL) {
        printf("-1\n");
        if (write_file == 1) {
          fclose(write);
        }
        free (baralho);
        free (c_Faces);
        free(c_Rank);
        exit(0);
      }
    }
    for (i = 0; i <= argc - 1; i++) {
      if (strcmp(argv[i], "-o") == 0) {
        if (i != 3) {
          if (write_file == 1) {
            fclose(write);
          }
          free (baralho);
          free (c_Faces);
          free(c_Rank);
          exit(0);
        }
      } else {
        if (argc == 5 && (((*(point+1) == 'd') && (*(point+2) == 'e') && (*(point+3) == 'c') && (*(point+4) == 'k')  &&  (*(point+5) == '\0'))
        || ((*(point+1) == 's') && (*(point+2) == 'h') && (*(point+3) == 'u') && (*(point+4) == 'f') && (*(point+5) == 'f') && (*(point+6) == 'l') && (*(point+7) == 'e') &&  (*(point+5) == '\0')))){
          printf("-1\n");
          if (write_file == 1) {
            fclose(write);
          }
          free (baralho);
          free (c_Faces);
          free(c_Rank);
          exit(0);
        }
      }
    }
  }

  if (times != 0) {
    switch (argc)
    {
      case 10:
      case 9:
      case 7:
      case 5:
      for (i = 2; i <= argc+1; i++)
      {

        for (j=i+1; j <= (argc+1) && argc != 10; j++){                                     // Verifica que no caso de 5,7 ou 9 cartas nao ha cartas repetidas.
          if ((c_Faces[i] == c_Faces[j]) && (c_Rank[i] == c_Rank[j]))
          {
            result = -1;
            Estatisticas(time);
            return;
          }
        }
        if (i<6 && argc == 10)                                                          // Verifica que no caso de 10 cartas nao ha repetidas nas 5 primeiras.
        {
          for (j= i+1; j<=6; j++)
          {
            if ((c_Faces[i] == c_Faces[j]) && (c_Rank[i] == c_Rank[j]))
            {
              result = -2;
              Estatisticas(time);
              Estatisticas(time);
              return;
            }
          }
        }
        if (i>6 && argc == 10)                                                          // Verifica que no caso de 10 cartas n�o ha repetidas nas 5 ultimas.
        {
          for (j= i+1; j<=11; j++)
          {
            if ((c_Faces[i] == c_Faces[j]) && (c_Rank[i] == c_Rank[j]))
            {
              result = -3;
              Estatisticas(time);
              Estatisticas(time);
              return;
            }
          }
        }
        n=0;
        while (c_Rank[i] != naipe[n] && n<=2)         // Verifica se s� usam os nipes admitidos
        {
          n++;
        }
        if (c_Rank[i] != (naipe[n]))
        {
          result = -1;
          Estatisticas(time);
          return;
        }
        v=0;
        while (c_Faces[i] != valor[v] && v<=11)         // Verifica se s� usam os valores admitidos
        {
          v++;
        }
        if (c_Faces[i]!= valor[v])
        {
          result = -1;
          Estatisticas(time);
          return;
        }
      }
      break;
      default:
      break;
    }
  }
  times++;
}

void ModeDx(char*baralho, int nr_baralhos, int argc, char *c_Faces, char *c_Rank, int mode, int Faces[]){

  // Esta função realiza o modo dx, o modo que mais se aproxima de um jogo de poker.

  char  Hands[32] = {0};
  register int   j = 0, i = 0, a = 0, b = 0, c = 0 , e = 0, k = 0, z = 0, d = 0;
  int   end  = 0;
  int   MaoPlayer[9] = {0};
  int   max = 0;
  int   winner = 0;
  int   count = 0;
  char  GuardaMesa[10] = {0};
  int   desempate[9] = {0};
  int   maior = 0;
  int   Empate = 0;
  int   sair = 0;

  for (i = 0; i < 9; i++) {
    empates[i] = 0;
  }
  for (i = 0; i < 13; i++) {
    c_Faces[i] = 0;
    c_Rank[i] = 0;
  }
  for   (i = 0; i < 9; i++) {
    In_Game[i] = 0;
  }
  static int  loop = 0;
  end = loop*104;
  loop++;
  j = 0;
  for (i = 1; i < 9; i++) {                                                        // Distribuiçao de duas cartas por cada jogadore ativo
    if (Player[i] == 1) {
      switch (i) {
        case 1:
        for (j = 0; j < 4 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 2:
        for (j = 4; j < 8 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 3:
        for (j = 8; j < 12 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 4:
        for (j = 12; j < 16 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 5:
        for (j = 16; j < 20 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 6:
        for (j = 20; j < 24 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 7:
        for (j = 24; j < 28 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
        case 8:
        for (j = 28; j < 32 ; j++) {
          Hands[j] = baralho[end];
          end++;
        }
        break;
      }
    }
  }
  z = 1;
  for (i = 1; i < 9; i++) {                                                       // identificação da mão que cada jogador possui (As duas cartas que receberam + as cinco da mesa)
    if (Player[i] == 1) {
      argc = 7;
      a = 4 * i;
      b = 0;
      c = 0;
      j = 2;
      e = 0;
      for ( k =(a-4) ; k < a; k+=2){

        c_Faces[j] = Hands[k];
        c_Rank[j] = Hands[k+1];
        j++;
      }
      for ( b = end; b < end+10; b+=2) {
        c_Faces[j] = baralho[b];
        c_Rank[j] = baralho[b+1];
        GuardaMesa[e] = baralho[b];
        GuardaMesa[e+1] = baralho[b+1];
        e+=2;
        j++;
      }
      mode = 3;
      argc = 7;
      ConverteFaces(argc, Faces, c_Faces, c_Rank);
      TipoDeMao(argc, Faces,c_Faces, c_Rank);
      for ( c = 0; c < 10; c++)
      {
        if (VerificaHand[c] != 0)
        {
          MaoPlayer[i] = VerificaHand[c];
        }
      }
      In_Game[z] = Fold (MaoPlayer, i);                                           // Chamada da funçao Fold, para verificar se o jogador vai ou nao a jogo.
      z++;
    }
  }
  for (i = 0; i < 14; i++) {
    c_Faces[i] = 0;
    c_Rank[i] = 0;
    Faces[i] = 0;
  }
  j = 0;
  e = 1;
  while (e != 9) {
    if (In_Game[e] != 0) {
      In_Game[j] = In_Game[e];
      In_Game[e] = 0;
      j++;
      max = j;
    }
    e++;
  }
  for (i = 0; i < 9; i++) {                                                       // Verificar quantos jogadores estao em jogo
    if (In_Game[i] != 0) {
      count++;
    }
  }
  i = 0;
  b = 0;
  c = 0;
  j = 0;

  if (count!= 0){                                                                 // Verificaçao do vencedor da ronda, apenas se estiver pelo menos um jogador em jogo
    for ( i = 0; i < max-1; i++) {
      for ( a = i+1; a < max; a++) {
        if (MaoPlayer[In_Game[a]] > MaoPlayer[In_Game[i]] && sair == 0) {
          maior = In_Game[a];
        } else if (MaoPlayer[maior] < MaoPlayer[In_Game[i]]) {
          maior = In_Game[i];
        }
      }
      sair++;
    }
    for (i = 0; i < max; i++) {
      if (MaoPlayer[In_Game[i]] == MaoPlayer[maior]) {
        Empate++;
        desempate[j] = In_Game[i];
        j++;
      }
    }
    b = 0;
    a = 0;
    d = 1;
    if (Empate != 0) {                                                             // Desempate caso haja mais que um jogador com o mesmo tipo de mao e essa mao seja a de maior valor de entre todos os jogadores em jogo.
      i = 0;                                                                       // O desempate é realizado pelos mesmos critérios que foram indicados no modo -c.
      j = 2;
      while (desempate[i+1] != 0 ){
        i++;
        j = 2;
        c = desempate[a] * 4;
        for (k =(c-4) ; k < c; k+=2){
          c_Faces[j] = Hands[k];
          c_Rank[j] = Hands[k+1];
          j++;
        }
        c = desempate[i] * 4;
        for (k =(c-4) ; k < c; k+=2){
          c_Faces[j] = Hands[k];
          c_Rank[j] = Hands[k+1];
          j++;
        }
        for ( b = 0; b < 10; b+=2) {
          c_Faces[j] = GuardaMesa[b];
          c_Rank[j] = GuardaMesa[b+1];
          j++;
        }
        mode = 4;
        argc = 9;
        ConverteFaces(argc, Faces, c_Faces, c_Rank);
        NoveCartas (argc, Faces,c_Faces, c_Rank, mode);
        if (result == 1) {
          maior = desempate[a];
        } else if (result == 2) {
          maior = desempate[i];
          a = i;
        } else if (result == 0){
          empates[0] = desempate[a];
          empates[d] = desempate[i];
          d++;
        }
      }
      count = 0;
      i = 0;
      while (i != d + 1) {
        if (maior !=  0 && maior != empates[i]) {
          count++;
        }
        if (count == (d+1)) {
          empates[0] = 0;
        }
        i++;
      }
      i = 0;
      while (i != d+1) {
        for ( j = i+1; j < d+2; j++) {
          if (empates[i] > empates[j] && empates[0]!= 0 && empates[j+1] != 0) {
            empates[j] = 0;
          }
        }
        i++;
      }
      winner = maior;
      for (i = 0; i < 14; i++) {
        c_Faces[i] = 0;
        c_Rank[i] = 0;
        Faces[i] = 0;
      }
    } else  winner = In_Game[maior];

    ImprimeCartasDx(GuardaMesa, c_Faces, c_Rank, Hands, argc, Faces, mode, winner);     // Depois de identificar o vencedor entra na função ImprimeCartasDx
    if (write_file == 1) {
      fprintf(write, "\n");
    } else printf("\n");
  }
  PlayerOn();
}

int Fold (int*MaoPlayer, int j){

  // Esta função verifica se um jogador vai ou nao a jogo e faz a contagem de quantos folds consecutivos fizeram.

  static int Fold[9] = {0};
  if (Fold[j] == 4 && Player[j] == 1){                                            // Caso tenham feito Fold 4 vezes consecutivas, esse jogador vai a jogo e a contagem volta a 0.
    Fold[j] = 0;
    return j;
  }
  else if ((MaoPlayer[j] >= j) && (Player[j] == 1)) {                            // Caso nao tenham feito Fold 4 vezes consecutivas e se a sua mao for maior que o seu indice, o jogador vai a jogo.
    Fold[j] = 0;                                                                 // Contagem volta a 0.
    return j;
  } else {
    Fold[j]++;
    return 0;
  }
}

void ImprimeCartasDx(char*GuardaMesa, char*c_Faces, char*c_Rank, char*Hands, int argc, int Faces[], int mode, int winner){

  // Esta função imprime as mãos de cada um dos jogadores em jogo de seguida imprime a mao do vencedor.
  // Em caso de empate imprime a mão do jogador de menor indice (de entre os empatados) e o indice dos jogadores empatados.

  int k = 0, a = 0, i = 0, j = 2, b = 0, time = 0;
  while (In_Game[i] != 0 ) {
    a = 4 * In_Game[i];
    j = 2;
    for ( k =(a-4) ; k < a; k+=2){

      c_Faces[j] = Hands[k];
      c_Rank[j] = Hands[k+1];
      j++;
    }
    for ( b = 0; b < 10; b+=2) {
      c_Faces[j] = GuardaMesa[b];
      c_Rank[j] = GuardaMesa[b+1];
      j++;
    }
    if (write_file == 1) {
      fprintf(write,"%d ", In_Game[i]);
    } else printf("%d ", In_Game[i]);
    mode = 3;
    argc = 7;
    ConverteFaces(argc, Faces, c_Faces, c_Rank);
    SeteCartas (argc, Faces,c_Faces, c_Rank, mode, winner);
    i++;
  }
  time = 1;
  Estatisticas_2(time, winner, empates);
  if (write_file == 1) {
    fprintf(write,"W ");
  } else printf("W ");

  if (empates[0] != 0) {
    a = 4 * empates[0];
  } else   a = 4 * winner;
  j = 2;
  for ( k =(a-4) ; k < a; k+=2){

    c_Faces[j] = Hands[k];
    c_Rank[j] = Hands[k+1];
    j++;
  }
  for ( b = 0; b < 10; b+=2) {
    c_Faces[j] = GuardaMesa[b];
    c_Rank[j] = GuardaMesa[b+1];
    j++;
  }
  mode = 5;
  argc = 7;
  ConverteFaces(argc, Faces, c_Faces, c_Rank);
  SeteCartas (argc, Faces,c_Faces, c_Rank, mode, winner);
  time = 0;
  Estatisticas_2(time, winner, empates);
  if (empates[0] != 0) {
    if (write_file == 1) {
      fprintf(write,"%d", empates[0]);
      for (i = 1; i < 9; i++) {
        if (empates[i]!= 0) {
          fprintf(write," %d", empates[i]);
        }
      }
      fprintf(write,"\n");

    } else{
      printf("%d", empates[0]);
      for (i = 1; i < 9; i++) {
        if (empates[i]!= 0) {
          printf(" %d", empates[i]);
        }
      }
      printf("\n");
    }
  }
}

void PlayerOn(){

  // Esta funçao verifica quais sao os jogadores  que irão estar ativos nas proximas rondas ( quer vao receber cartas)

  static int count[9] = {0};
  static int times = 0;
  int here[9] = {0};
  times++;
  static int consecutive[17] = {0};
  static int sair[9] = {0};
  int i = 0;
  for (i = 0; i < 9; i++) {
    switch (In_Game[i]) {
      case 1:
      count[1]++;
      here[1]++;
      if (sair[1] == 0) {
        consecutive[1] = times;
        sair[1]++;
      }else consecutive[2] = times;
      break;
      case 2:
      count[2]++;
      here[2]++;
      if (sair[2] == 0) {
        consecutive[3] = times;
        sair[2]++;
      }else consecutive[4] = times;
      break;
      case 3:
      count[3]++;
      here[3]++;
      if (sair[3] == 0) {
        consecutive[5] = times;
        sair[3]++;
      }else consecutive[6] = times;

      break;
      case 4:
      count[4]++;
      here[4]++;
      if (sair[4] == 0) {
        consecutive[7] = times;
        sair[4]++;
      }else consecutive[8] = times;
      break;
      case 5:
      count[5]++;
      here[5]++;
      if (sair[5] == 0) {
        consecutive[9] = times;
        sair[5]++;
      }else consecutive[10] = times;
      break;
      case 6:
      count[6]++;
      here[6]++;
      if (sair[6] == 0) {
        consecutive[11] = times;
        sair[6]++;
      }else consecutive[12] = times;
      break;
      case 7:
      count[7]++;
      here[7]++;
      if (sair[7] == 0) {
        consecutive[13] = times;
        sair[7]++;
      }else consecutive[14] = times;
      break;
      case 8:
      count[8]++;
      here[8]++;
      if (sair[8] == 0) {
        consecutive[15] = times;
        sair[8]++;
      }else consecutive[16] = times;
      break;
    }
    if (count[i] == 2 && (consecutive[2*i] - consecutive[(2*i)-1] == 1)){         // Caso o jogador tenha ido a jogo duas vezes consecutivas nao estará ativo na proxima ronda.
      Player[i] = 0;
      count[i] = 0;
      consecutive[2*i] = 0;
      consecutive[(2*i)-1] = 0;
      sair[i] = 0;
    }else {
      Player[i] = 1;
      if (here[i] == 0) {
        sair[i] = 0;
        count[i] = 0;
      }
    }
  }
}

void Estatisticas_2(int time, int winner, int empates[]){

  // Esta função realiza as Estatisticas do modo dx.
  // É chamada 3 vezes ao longo do codigo do modo dx.
  // O que esta função realiza depende do valor da variavel time, que é passada como argumento, cada vez que é chamada.

  int PokerHand = 0;
  double point = 1;
  double   count_empates = 0;
  static double count = 0;
  int i = 0, j = 0, x = 0;
  double aux = 0;
  static double count_type[11] = {0};
  static double resultado[9] = {0};
  static double statics[11] = {0};
  int   guardar[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  for (i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      PokerHand = VerificaHand[i];
    }
  }
  switch (time) {
    case 0:
    count++;
    switch (PokerHand)
    {
      case 1:
      count_type[1]++;
      break;
      case 2:
      count_type[2]++;
      break;
      case 3:
      count_type[3]++;
      break;
      case 4:
      count_type[4]++;
      break;
      case 5:
      count_type[5]++;
      break;
      case 6:
      count_type[6]++;
      break;
      case 7:
      count_type[7]++;
      break;
      case 8:
      count_type[8]++;
      break;
      case 9:
      count_type[9]++;
      break;
      case 10:
      count_type[10]++;
      break;
      default:
      break;
    }
    break;
    case 1:
    if (empates[0]!= 0 ) {
      for ( i = 0; i < 9; i++) {
        if (empates[i]!= 0) {
          count_empates++;
        }
      }
      point = (double)(1/count_empates);

      for (i = 0; i < 9; i++) {
        if (empates[i]!= 0) {
          resultado[empates[i]]+=point;
        }
      }
    } else{
      resultado[winner]++;
}
break;
case 2:
x = 1;
for (i = 1; i < 8 ; i++) {
  for ( j = i+1; j < 9; j++) {
    if (resultado[i] < resultado[j]){
      aux = resultado[i];
      resultado[i] = resultado[j];
      resultado[j] = aux;
      x = guardar[i];
      guardar[i] = guardar[j];
      guardar[j] = x;
    }
  }
}
for ( i = 1; i < 11; i++)
{
  statics[i] = (double)(count_type[i]/count);
  if (write_file == 1)
  {
    fprintf(write,"%d %.2E\n",i, statics[i]);
  } else
  {
    printf("%d %.2E\n",i, statics[i]);
  }
}
for (i = 1; i < 8 ; i++) {
  for ( j = i+1; j < 9; j++) {
    if ((resultado[i] == resultado[j]) && (guardar[i] > guardar[j])){
      aux = resultado[i];
      resultado[i] = resultado[j];
      resultado[i] = aux;
      x = guardar[i];
      guardar[i] = guardar[j];
      guardar[j] = x;
    }
  }
}
if (write_file == 1)
{
  fprintf(write,"\n");
  for ( i = 1; i <9; i++)
  {
    fprintf(write,"%d %.2f\n", guardar[i], resultado[i]);
  }
} else
{
  printf("\n");
  for ( i = 1; i < 9; i++)
  {
    printf("%d %.2f\n", guardar[i], resultado[i]);
  }
}
break;
default:
break;
}
}
