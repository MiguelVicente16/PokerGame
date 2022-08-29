#include "main.h"
#include "Linha_Comando.h"
#include "Modos_d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// -------------------------------------------------------------------ConverteFaces-----------------------------------------------------------//
void ConverteFaces (int argc, int Faces[], char *c_Faces, char *c_Rank){
  // Converte o valor das cartas em inteiros colocando-os no vetor Faces;
  int i;
  for (i=2; i<=argc+1; i++)
  {
    if (c_Faces[i]=='A')
    {
      Faces[i] = 14;
    }
    else if (c_Faces[i]=='K')
    {
      Faces[i] = 13;
    }
    else if (c_Faces[i]=='Q')
    {
      Faces[i] = 12;
    }
    else if (c_Faces[i]=='J')
    {
      Faces[i] = 11;
    }
    else if (c_Faces[i]=='T')
    {
      Faces[i] = 10;
    }
    else if (c_Faces[i]=='9')
    {
      Faces[i] = 9;
    }
    else if (c_Faces[i]=='8')
    {
      Faces[i] = 8;
    }
    else if (c_Faces[i]=='7')
    {
      Faces[i] = 7;
    }
    else if (c_Faces[i]=='6')
    {
      Faces[i] = 6;
    }
    else if (c_Faces[i]=='5')
    {
      Faces[i] = 5;
    }
    else if (c_Faces[i]=='4')
    {
      Faces[i] = 4;
    }
    else if (c_Faces[i]=='3')
    {
      Faces[i] = 3;
    }
    else if (c_Faces[i]=='2')
    {
      Faces[i] = 2;
    }
  }
  return;
}
// -------------------------------------------------------------------ConverteFaces_End------------------------------------------------------------------------//

// ---------------------------------------------------------------------OrganizaFaces-----------------------------------------------------------//
void OrganizaFaces(int argc,int Faces[],char *c_Faces, char *c_Rank){
  int i;
  int j;
  switch (argc)                                  // O codigo analisa o caso de 10 cartas como dois conjuntos de 5 cartas e o caso de 9 cartas como dois conjuntos de 7
  {
    case 10:
    argc = 5;
    break;
    case 7:
    case 9:
    argc = 7;
    break;
    default:
    break;
  }
  for ( i = 2; i < (argc+1); i++)                // Organiza os valores no vetor Faces do maior para o menor
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (Faces[i] < Faces[j])
      {
        Faces[0] = Faces[i];
        Faces[i] = Faces[j];
        Faces[j] = Faces[0];
        Faces[0] = 0;
      }
    }
  }
  return;
}
// ---------------------------------------------------------------------OrganizaFaces_End---------------------------------------------------------------------------//

// -------------------------------------------------- OrganizaFacesPosNaipesString----------------------------------------//
void OrganizaFacesPosNaipesString(int argc,char *c_Faces, char *c_Rank){
  // Depois do vetor argv estar organizado por naipes � organizado por valores.
  switch (argc)                                                   // O codigo analisa o caso de 10 cartas como dois conjuntos de 5 cartas e o caso de 9 cartas como dois conjuntos de 7.
  {
    case 10:
    argc = 5;
    break;
    case 7:
    case 9:
    argc = 7;
    break;
    default:
    break;
  }
  int i = 2;
  int j = 0;
  for ( i = 2; i < (argc+1); i++)                                 // Organiza por valores as cartas que t�m os naipes iguais.
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (c_Faces[i] < c_Faces[j] && c_Rank[i] == c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
    }
  }

  for ( i = 2; i < (argc+1); i++)                                 // Organiza por valores as cartas com figuras que t�m os naipes iguais.
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (c_Faces[j] == 'A' && c_Rank[i] == c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[j] == 'K' && c_Rank[i] == c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[j] == 'Q' && c_Rank[i] == c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[i] == 'J' && c_Faces[j] == 'Q' && c_Rank[i] == c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[i] == 'T' && c_Faces[j] == 'J' && c_Rank[i] == c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
    }
  }

  return;
}
// -------------------------------------------------- OrganizaFacesPosNaipesString_End----------------------------------------//

// --------------------------------------------------------------------- OrganizaFacesString -----------------------------------------------------------//
void OrganizaFacesString(int argc,char *c_Faces, char *c_Rank){
  //  Organiza o vetor argv por valores por ordem decrescente
  switch (argc)                                       // O codigo analisa o caso de 10 cartas como dois conjuntos de 5 cartas e o caso de 9 cartas como dois conjuntos de 7.
  {
    case 10:
    argc = 5;
    break;
    case 7:
    case 9:
    argc = 7;
    break;
    default:
    break;
  }
  int i = 2;
  int j = 0;
  for ( i = 2; i < (argc+1); i++)                     // Organiza cartas de valor num�rico
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (c_Faces[i] < c_Faces[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
    }
  }
  for ( i = 2; i <= argc; i++)                     // Organiza cartas com figuras
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (c_Faces[j] == 'A')
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[j] == 'K')
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[j] == 'Q')
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];;
      }
      else if (c_Faces[i] == 'J' && c_Faces[j] == 'Q')
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
      else if (c_Faces[i] == 'T' && c_Faces[j] == 'J')
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }

    }
  }

  return;
}
// --------------------------------------------------------------------- OrganizaFacesString_End-----------------------------------------------------------//

//--------------------------------------------------------------OrganizaNaipesString-------------------------------------------------------------//
void OrganizaNaipesString(int argc ,char *c_Faces, char *c_Rank){
  int i, j;
  switch (argc)                                       // O codigo analisa o caso de 10 cartas como dois conjuntos de 5 cartas e o caso de 9 cartas como dois conjuntos de 7.
  {
    case 10:
    argc = 5;
    break;
    case 7:
    case 9:
    argc = 7;
    break;
    default:
    break;
  }
  for ( i = 2; i < (argc+1); i++)                      // Organiza as  cartas em fun��o dos naipes por ordem alfab�tica, de cartas com o mesmo valor.
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (c_Rank[i] > c_Rank[j] && c_Faces[i]== c_Faces[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
    }
  }
}
//--------------------------------------------------------------OrganizaNaipesString_End-------------------------------------------------------------//

//------------------------------------------------------------OrganizaNaipesString2-----------------------------------------------------//
void OrganizaNaipesString2(int argc,char *c_Faces, char *c_Rank){
  int i, j;
  switch (argc)                                       // O codigo analisa o caso de 10 cartas como dois conjuntos de 5 cartas e o caso de 9 cartas como dois conjuntos de 7.
  {
    case 10:
    argc = 5;
    break;
    case 7:
    case 9:
    argc = 7;
    break;
    default:
    break;
  }
  for ( i = 2; i < (argc+1); i++)                     // Organiza as  cartas em fun��o dos naipes por ordem alfab�tica.
  {
    for ( j = (i +1); j <= (argc+1); j++)
    {
      if (c_Rank[i] > c_Rank[j])
      {
        c_Faces[0] = c_Faces[i];
        c_Faces[i] = c_Faces[j];
        c_Faces[j] = c_Faces[0];

        c_Rank[0] = c_Rank[i];
        c_Rank[i] = c_Rank[j];
        c_Rank[j] = c_Rank[0];
      }
    }
  }
}
//------------------------------------------------------------OrganizaNaipesString2_End-----------------------------------------------------//

//----------------------------------------------------------------------TipoDeMao-------------------------------------------------------------//
void TipoDeMao(int argc, int Faces[],char *c_Faces, char *c_Rank){
  int j = 0, i = 0, count = 0, h = 0, t = 0, sair = 0, u= 0, a= 0, paircount[3] = {0}, k = 0, b= 0, dois= 0, tres= 0, change = 0, PokerHand = 0, controlo = 0, loop = 0;
  switch (argc)                                           // O codigo analisa o caso de 10 cartas como dois conjuntos de 5 cartas e o caso de 9 cartas como dois conjuntos de 7.
  {

    case 10:
    argc = 5;
    break;
    case 7:
    case 9:
    argc = 7;
    break;
    default:
    break;
  }
  for (i = 0; i < 10; i++)
  {
    VerificaHand[i] = 0;
  }
  VerificaHand[0] = 1;
  for (i = 0; i < 5; i++)
  {
    Straight[i] = 0;
    StraightFlush[i] = 0;
    Flush[i] = 0;

  }

  //-------------ROYALFLUSH:10-------------//
  OrganizaNaipesString2(argc, c_Faces, c_Rank);
  OrganizaFacesPosNaipesString(argc,c_Faces, c_Rank);
  j = 0;
  i = 2;
  for (i = 2; i < (argc+1); i++)
  {
    if (c_Faces[i] == 'A')
    {
      if(c_Faces[i+1]== 'K' && c_Rank[i+1] == c_Rank[i])
      {
        if(c_Faces[i+2] == 'Q' && c_Rank[i+2] == c_Rank[i])
        {
          if(c_Faces[i+3] == 'J' && c_Rank[i+3] == c_Rank[i])
          {
            if(c_Faces[i+4] == 'T' && c_Rank[i+4] == c_Rank[i])
            {
              VerificaHand[9] = 10;
              return;
            }
          }
        }
      }
    }
  }
  //-------------END ROYALFLUSH:10-------------//
  OrganizaFacesString(argc,c_Faces, c_Rank);
  OrganizaNaipesString(argc,c_Faces, c_Rank);
  OrganizaFaces(argc,Faces,c_Faces, c_Rank);
  //-------------FLUSH:6-------------//
  count= 1;
  i = 2;
  j = 1;
  while ( i <= argc && count < 5)
  {
    for (u = (i +1); u < argc + 2; u++)
    {
      if(c_Rank[i] == c_Rank[u])
      {
        count++;
        Flush[0]=i;
        Flush[j] = u;
        j++;
      }
    }
    if ( count < 5)
    {
      j = 1;
      count = 1;
    }
    i++;
  }
  if (count >= 5)
  {
    VerificaHand[5] = 6;
  }
  else
  {

    VerificaHand[5] = 0;
  }
  //-------------FLUSH:6-------------//

  //-----------STRAIGHT:5-----------//
  Straight[4]= 0;
  count = 1;
  h = 0;
  t = 0;
  sair = 0;
  j = 0;
  count = 1;
  if (Faces[2] == 14)
  {
    for (i=2; i<=argc+1; i++)
    {
      if (Faces[i] == 5 )
      {   j = i;
        for (i=j; i<=argc+1; i++)
        {
          if (Faces[i] == 4)
          {    j = i;
            for (i=j; i<=argc+1; i++)
            {
              if (Faces[i] == 3 )
              {  j = i;
                for (i=j; i<=argc+1; i++)
                {
                  if (Faces[i] == 2 )
                  {
                    for (i=2; i<=argc+1; i++)
                    {
                      if (Faces[i]== 14)
                      {
                        Faces[i] = 1;
                      }
                    }
                    change = 1;
                    VerificaHand[4] = 5;
                    OrganizaFaces(argc,Faces,c_Faces, c_Rank);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  for (i = 2; i < argc +1 && count < 6 && sair !=1; i++)
  {
    if((Faces[i] - Faces[i+1] == 1) || ((Faces[i]- Faces[i+2] == 1) && ((i+2) < argc) && (argc == 5)) || ((Faces[i] - Faces[i+3] == 1) && ((i+3) < argc-1) && (argc == 5)) \
    || ((Faces[i]- Faces[i+2] == 1) && (argc==7))|| ((Faces[i] - Faces[i+3] == 1) && (argc==7)))
    {
      Straight[t] = i;
      count++;
      t++;
      if((count==5) && (Faces[i] - Faces[i+1] == 1)){
        Straight[4] = i+1;
        sair++;
      }
      if((Faces[i] - Faces[i+2] == 1) && (Faces[i] - Faces[i+1] != 1))
      {
        i+=1;
        if(count==5  && (Straight[4] == 0)){
          Straight[4] = i+1;
          sair++;
        }
      } else if ((Faces[i] - Faces[i+3] == 1) && (Faces[i] - Faces[i+1] != 1) && (Faces[i] - Faces[i+2] != 1))
      {
        i= i + 2;
        if(count==5  && (Straight[4] == 0)){
          Straight[4] = i+1;
          sair++;
        }
      }
    }else if(count < 5){
      count = 1;
      t = 0;
    };
  }
  if (count >= 5)
  {
    VerificaHand[4] = 5;
  }
  //-----------STRAIGHT:5-----------//
  if (VerificaHand[4] == 5 && VerificaHand[5] == 6)
  {
    //-----------STRAIGHT FLUSH:9-----------//
    if (change == 1)
    {
      OrganizaArgvA1(argc, Faces,c_Faces, c_Rank);
    }
    t = 0;
    sair = 0;
    count = 1;
    if (argc == 5){
      for (i = 0; i < 5; i++)
      {
        if (Flush[i] == Straight[i]){
          StraightFlush[i] = Flush[i];
          count ++;
        }
      }
      if (count >= 5 && VerificaHand[9] != 10)
      {
        VerificaHand[8] = 9;
      }
    }else if ( argc == 7){
      for (i = 2; i < (argc + 1) && count<6 && sair != 1; i++)
      {
        if(((Faces[i] - Faces[i+1] == 1) && (c_Rank[i] == c_Rank[i+1])) || ((Faces[i]- Faces[i+2] == 1) &&  (c_Rank[i]== c_Rank[i+2])) || ((Faces[i] - Faces[i+3] == 1) &&  (c_Rank[i] == c_Rank[i+3])))
        {
          StraightFlush[t] = i;
          count++;
          t++;
          controlo = 0;
          if((count==5) && ((Faces[i] - Faces[i+1] == 1) &&  (c_Rank[i] == c_Rank[i+1]))){
            StraightFlush[4] = i+1;
            sair++;
          }
          if ((Faces[i] - Faces[i+1] == 1) && (c_Rank[i] == c_Rank[i+1]))
          {

          }else if (((Faces[i]- Faces[i+2] == 1) &&  (c_Rank[i] == c_Rank[i+2])) && ((Faces[i] - Faces[i+1] != 1) || (c_Rank[i] != c_Rank[i+1])) )
          {
            i= i + 1;
            controlo = 1;
            if(count==5){
              StraightFlush[4] = i+1;
              sair++;
            }
          } else if ((Faces[i] - Faces[i+3] == 1) &&  (c_Rank[i] == c_Rank[i+3]))
          {
            i= i + 2;
            if(count==5){
              StraightFlush[4] = i+1;
              sair++;
            }
          }
        }else if(count < 5){
          if (controlo == 1 && i ==4 && loop == 0)
          {
            i = i - 2;
            loop++;
          } else if (controlo == 1 && i ==4 && loop == 1)
          {
            i = i;
          }
          count = 1;
          t = 0;
        }
      }
    }
    if (count >= 5 && VerificaHand[9] != 10)
    {
      VerificaHand[8] = 9;
    }
    //-----------STRAIGHT FLUSH:9-----------//
  }
  //-----------------Pair:2 & Two pair:3 & Three of a kind:4 & Full house:7 & Four of a kind:8-------------------//
  i = 2;
  h = 1;      // conta o numero de valores iguais
  a = 1;
  while ( (i <= argc) && (h != 4))
  {
    for (j = (i+1); j <= argc+1; j++)
    {
      if (Faces[i] == Faces[j])
      {
        h++;
        FourKind[0] = i;
        FourKind[a] = j;
        a++;
      }
    }
    if (h < 4)
    {
      h = 1;
      a = 1;
    }
    i++;
  }
  if (h == 4 )
  {   VerificaHand[7]= 8;                                 // Four Of a Kind
  }
  h = 1;
  k = 0;
  i = 2;
  a = 0;
  b = 0;
  while (( h != 3) && (h !=2) && (i<=argc) && VerificaHand[7]!= 8)
  {
    for (j = i+1; (j <= argc+1); j++)
    {
      if (Faces[i] == Faces[j])
      {

        h++;
        Pair[a]= i;
        a++;
        Pair[a] = j;
        Trio[b]= j-1;
        b++;
        Trio[b] = j;
      }
    }
    if (h != 1)
    {
      paircount[k] = h;
      if (h == 2)
      {
        a++;
      } else if (h==3){
        b++;
      }
      k++;
    }
    if (h==3)
    {
      i=i+3;
    }
    else {
      i++;
    }
    if (h <= 3)
    {
      h = 1;
    }
  }

  k=0;
  dois=0, tres=0;
  for (i=0; i<3; i++)
  {
    if (paircount[i]==2)
    {
      dois++;
    }
    if (paircount[i]==3)
    {
      tres++;

    }
  }
  if (dois == 1 && tres != 1)
  {
    VerificaHand[1]= 2;                 // pair
  }
  if (dois >= 2)
  {
    VerificaHand[2]= 3;                 // two pair
  }
  if (tres == 1 && dois <1)
  {
    VerificaHand[3]=4;                  // three of a kind
  }
  if ((dois >= 1 && tres == 1) || tres == 2)
  {
    VerificaHand[6] = 7;                // Full House
  }
  //-----------------Pair:2 & Two pair:3 & Three of a kind:4 & Full house:7 & Four of a kind:8-------------------//
  for (i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      PokerHand = VerificaHand[i];
    }
  }
  if (PokerHand != 9 && PokerHand != 5 && change == 1)
  {
    ReOrganizaArgvA1 (argc, Faces, c_Faces, c_Rank, change);
    ChangeBack(Faces, change);
    OrganizaFaces(argc,Faces,c_Faces, c_Rank);
  }
  return;
}
//----------------------------------------------------------------------TipoDeMao_End-------------------------------------------------------------//

//----------------------------------------------------------------------CincoCartas-------------------------------------------------------------//
void CincoCartas( int argc, int Faces[],char *c_Faces, char *c_Rank){
  // Esta função é chamada no modo -c e no modo di, no caso d1.

  int PokerHand = 1;
  int i= 0;;
  TipoDeMao (argc, Faces,c_Faces, c_Rank);
  for (i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      PokerHand = VerificaHand[i];
    }
  }
  if (write_file == 1)
  {
    fprintf(write,"%i\n", PokerHand);
  }else
  {
    printf("%i\n", PokerHand);                  // Imprime o resultado da m�o introduzida
  }
  return;
}
//----------------------------------------------------------------------CincoCartas_End-------------------------------------------------------------//

//----------------------------------------------------------------------DEZCartas-------------------------------------------------------------//
void DezCartas ( int argc, int Faces[], char *c_Faces, char *c_Rank, int mode){

  // Esta função é chamada no modo -c e no modo di, no caso d4.

  int Compare1[7] = {0};
  int Compare2[7] = {0};
  int prox = 0;
  int SaveMao1[2] = {0};
  int SaveMao2[2] = {0};
  int S_Flush[7] = {0};
  int SaveF, SaveT, SaveP, i, Mao1 = 0, Mao2 = 0;
  int time = 0;
  if (result != -2)                          // Esta condição apenas ocorre nos modos di.
  {
    time = 3;
    TipoDeMao(argc, Faces,c_Faces, c_Rank);
  }
  if (mode == 2 && result != -2)             // Esta condição apenas ocorre nos modos di.
  {
    time = 0;
    Estatisticas(time);
  }
  for ( i = 0; i < 10; i++)                  // Coloca na variavel Mao1 o valor do tipo de mao das primeiras 5 cartas
  {
    if (VerificaHand[i] != 0)
    {
      Mao1 = VerificaHand[i];
    }
  }
  SaveF = Guarda_Vect(prox, argc, Mao1, Faces);
  SaveT = Guarda_Vect(prox, argc, Mao1, Faces);
  prox++;
  SaveP = Guarda_Vect(prox, argc, Mao1, Faces);
  SaveMao1[0] = SaveP;
  SaveMao1[1] = SaveT;

  for ( i = 2; i < 7; i++)                  // Coloca o valor das primeiras 5 cartas no vetor Compare1[].
  {
    Compare1[i] = Faces[i];
  }
  for (i = 2; i <= 6; i++)                  // Coloca nas posi��es 2 a 6 da string argv a segunda m�o
  {
    c_Faces[i] = c_Faces[i+5];
    c_Rank[i] = c_Rank[i+5];
    Faces[i] = Faces[i+5];
  }
  OrganizaFaces(argc, Faces,c_Faces, c_Rank);
  if (result != -3)                             // Esta condição apenas ocorre nos modos di.
  {
    time = 3;
    TipoDeMao(argc, Faces,c_Faces, c_Rank);
  }
  if (mode == 2 && result != -3)                // Esta condição apenas ocorre nos modos di.
  {
    time = 0;
    Estatisticas(time);
  }
  for (i = 0; i < 5; i++)
  {
    S_Flush[i] = Flush[i];
  }
  for ( i = 0; i < 10; i++)               // Coloca na vari�vel Mao2 o valor do tipo de m�o das ultimas 5 cartas
  {
    if (VerificaHand[i] != 0)
    {
      Mao2 = VerificaHand[i];
    }
  }
  prox = 0;
  SaveT = Guarda_Vect(prox, argc, Mao2, Faces);
  prox++;
  SaveP = Guarda_Vect(prox, argc, Mao2, Faces);
  SaveMao2[0] = SaveP;
  SaveMao2[1] = SaveT;
  for ( i = 2; i < 7; i++)                // Coloca o valor das ultimas 5 cartas no vetor Compare2[].
  {
    Compare2[i] = Faces[i];
  }
  if(result == -2 || result == -3){      // Esta condição apenas ocorre nos modos di.

    if (write_file == 1)
    {
      fprintf(write,"-1\n");
    }else
    {
      printf("-1\n");
    }
  }
  else if (Mao1 > Mao2)                        // Verifica quem é o vencedor
  {
    result = 1;
    if (write_file == 1)                      // Esta condição apenas ocorre nos modos di.
    {
      fprintf(write,"%d\n", result);
    }else
    {
      printf("%d\n", result);
    }
  }
  else if (Mao1 < Mao2)
  {
    result = 2;
    if (write_file == 1)                    // Esta condição apenas ocorre nos modos di.
    {
      fprintf(write,"%d\n", result);
    }else
    {
      printf("%d\n", result);
    }
  }
  else if (Mao1 == Mao2 )
  {
    MesmoTipoMao(argc, Compare1, Compare2, Mao2, SaveF, SaveMao1, SaveMao2, S_Flush,c_Faces, c_Rank, mode);
  }
  return;
}
//----------------------------------------------------------------------DEZCartas_End-------------------------------------------------------------//

//----------------------------------------------------------------------SETECartas-------------------------------------------------------------//
void SeteCartas(int argc , int Faces[], char *c_Faces, char *c_Rank, int mode, int winner){

  // Esta função é chamada no modo -c e no modo di, no caso d2 e dx.

  int i, ValorMao = 0;
  TipoDeMao(argc, Faces,c_Faces, c_Rank);
  for ( i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      ValorMao = VerificaHand[i];
    }
  }
  if (mode != 4) {
    ChooseToPrint (ValorMao, argc, Faces,c_Faces, c_Rank);        // Imprime o tipo de m�o para 7 cartas.
                                                                  /* No modo dx quando a função NOVECartas é chamada, e dentro da NoveCartas quando a função SeteCartas é chamada,
                                                                   nada é imprimido. É por esse motivo que a aqui a função ChooseToPrint está dentro de um if.*/
  }
  if (argc == 7 && mode !=4)                                      // A condição mode != 4 apenas serve para nada ser imprimido no caso em que a função NoveCartas é chamada no modo dx.
  {
    if (write_file == 1)
    {
      if (mode == 5){
        fprintf(write,"%i ", ValorMao);
        if (empates[0] == 0) {
          fprintf(write,"%d\n", winner);
        }
      } else {fprintf(write,"%i\n", ValorMao);}

    }else
    {
      if (mode == 5) {                                                                 // A condição mode == 5 serve para que este if se realize apenas no modo dx quando a variavel mode é colocada a 5.
        printf("%i ", ValorMao);
        if (empates[0] == 0) {
          printf("%d\n", winner);
        }
      } else {printf("%i\n", ValorMao);}
    }
  } else if (argc == 9 && mode !=4 && mode != 5)                                      // Imprime o tipo de m�o para 9 cartas
  {
    if (write_file == 1)
    {
      fprintf(write,"%i ", ValorMao);
    }else
    {
      printf("%i ", ValorMao);
    }
  }
  return;
}
//----------------------------------------------------------------------SETECartas_End-------------------------------------------------------------//

//----------------------------------------------------------------------NOVECartas-------------------------------------------------------------//
void NoveCartas(int argc, int Faces[],char *c_Faces, char *c_Rank, int mode){

  // Esta função é chamada no modo -c e no modo di, no caso d3 e dx.

  char S_Argv[9][2];
  int S_Faces [14] = {0};
  int Compare1[9] = {0};
  int Compare2[9] = {0};
  int SaveMao1[2] = {0};
  int SaveMao2[2] = {0};
  int S_Flush[5] = {0};
  int winner = 0;
  int SaveF, SaveP, SaveT, i, j, prox= 0, PokerHand = 0, Mao1, Mao2, time = 0;

  for ( i = 2, j = 0; i < 11 && j < 9; i++, j++)
  {
    S_Argv[j][0] = c_Faces[i];
    S_Argv[j][1] = c_Rank[i];
    S_Faces[i-2] =  Faces[i];
  }
  for ( i = 6; i <=10; i++)
  {
    c_Faces[i-2] = c_Faces[i];
    c_Rank[i-2] = c_Rank[i];
    Faces[i-2] = Faces[i];
  }
  SeteCartas(argc, Faces,c_Faces, c_Rank, mode, winner);                          // A opçao 9 cartas sao duas maos de 7 cartas.
  if (mode == 2)                                                                  // Condição para os modos di, neste caso para o d3.
  {
    Estatisticas(time);
  }

  for (i = 0; i < 5; i++)
  {
    S_Flush[i] = Flush[i];
  }
  for ( i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      PokerHand = VerificaHand[i];
    }
  }
  SaveF = Guarda_Vect(prox, argc, PokerHand, Faces);
  SaveT = Guarda_Vect(prox, argc, PokerHand, Faces);
  prox++;
  SaveP = Guarda_Vect(prox, argc, PokerHand, Faces);
  SaveMao1[0] = SaveP;
  SaveMao1[1] = SaveT;
  for ( i = 2; i < 9; i++)
  {
    Compare1[i] = Faces[i];
  }
  Mao1 = PokerHand;
  for ( i = 2, j = 2; i < 11 && j < 9; i++, j++)
  {
    c_Faces[i] = S_Argv[j][0];
    c_Rank[i] = S_Argv[j][1];
    Faces[i] =  S_Faces[i];
  }
  SeteCartas(argc, Faces,c_Faces, c_Rank, mode, winner);
  if (mode == 2)                                                                  // Condição para os modos di, neste caso para o d3.
  {
    Estatisticas(time);
  }

  for ( i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      PokerHand = VerificaHand[i];
    }
  }
  prox = 0;
  SaveT = Guarda_Vect(prox, argc, PokerHand, Faces);
  prox++;
  SaveP = Guarda_Vect(prox, argc, PokerHand, Faces);
  SaveMao2[0] = SaveP;
  SaveMao2[1] = SaveT;
  for ( i = 2; i < 9; i++)
  {
    Compare2[i] = Faces[i];
  }
  Mao2 = PokerHand;
  if (Mao1 > Mao2)                                                                 // Verifica quem foi o vencedor
  {
    result = 1;
    if (write_file == 1 && mode!=4)
    {
      fprintf(write,"%d\n", result);
    }else if (mode!=4)
    {
      printf("%d\n", result);
    }
  }
  else if (Mao1 < Mao2)
  {
    result = 2;
    if (write_file == 1  && mode!=4)
    {
      fprintf(write,"%d\n", result);
    }else if(mode!=4)
    {
      printf("%d\n", result);
    }
  }
  else if (Mao1 == Mao2)
  {
    MesmoTipoMao(argc,  Compare1, Compare2, PokerHand, SaveF, SaveMao1, SaveMao2, S_Flush,c_Faces, c_Rank, mode);
  }
}
//----------------------------------------------------------------------NOVECartas_End-------------------------------------------------------------//

//----------------------------------------------------------------------ChooseToPrint-------------------------------------------------------------//
void ChooseToPrint (int ValorMao, int argc, int Faces[],char *c_Faces, char *c_Rank){

   // Vao ser imprimidas as cartas de acordo com o tipo de mao identificado, tanto para ficheiro, como para stdout, dependendo do modo (-c, -di ou -dx).

  int i, sair = 0, j = 0;

  switch (ValorMao)
  {
    case 10:
    for (i=2; i < (argc+1); i++)
    {
      if (c_Rank[i] == c_Rank[i+1] && c_Rank[i+1] == c_Rank[i+2])
      {
        for (j=i; j <= i+4 ; j++)
        {
          if (write_file == 1)
          {
            fprintf(write, "%c%c ", c_Faces[j], c_Rank[j]);
          } else
          {
            printf("%c%c ", c_Faces[j], c_Rank[j]);
          }
        }
        return;
      }
    }
    break;
    case 9:
    while (j<5)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[StraightFlush[j]], c_Rank[StraightFlush[j]]);
        j++;
      } else
      {
        printf("%c%c ", c_Faces[StraightFlush[j]], c_Rank[StraightFlush[j]]);
        j++;
      }
    }
    break;
    case 8:
    if(FourKind[0] != 2){
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[2], c_Rank[2]);
      } else
      {
        printf("%c%c ", c_Faces[2], c_Rank[2]);
      }
    }
    while (j<4)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[FourKind[j]], c_Rank[FourKind[j]]);
        j++;
      } else
      {
        printf("%c%c ", c_Faces[FourKind[j]], c_Rank[FourKind[j]]);
        j++;
      }
    }
    if (FourKind[0] == 2)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[FourKind[3]+1], c_Rank[FourKind[3]+1]);
      } else
      {
        printf("%c%c ", c_Faces[FourKind[3]+1], c_Rank[FourKind[3]+1]);
      }
    }
    break;
    case 7:
    if(Trio[5] != 0 && (Pair[1] - Pair[0] != 1) && Pair[3] - Pair[2] != 1)
    {
      while (j<5)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        }
      }
    }
    else if (Pair[1] - Pair[0] != 1)
    {
      while (j<3)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        }
      }
      j = 2;
      while (j<4)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
    }
    else
    {
      while (j<2)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
      for (i = 0; i < 5 && sair<1; i++)
      {
        if (c_Faces[Trio[i]] == c_Faces[Trio[i+2]])
        {
          j= i;
          sair++;
        }
      }
      i = j+3;
      while (j< i)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        }
      }
    }
    break;
    case 6:
    while (j<5)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[Flush[j]], c_Rank[Flush[j]]);
        j++;
      } else
      {
        printf("%c%c ", c_Faces[Flush[j]], c_Rank[Flush[j]]);
        j++;
      }
    }
    break;
    case 5:
    OrganizaArgvA1(argc, Faces,c_Faces, c_Rank);
    while (j<5)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[Straight[j]], c_Rank[Straight[j]]);
        j++;
      } else
      {
        printf("%c%c ", c_Faces[Straight[j]], c_Rank[Straight[j]]);
        j++;
      }
    }
    break;
    case 4:
    if (Trio[0]==2){
      while (j<3)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c %c%c ", c_Faces[5], c_Rank[5], c_Faces[6], c_Rank[6]);
      } else
      {
        printf("%c%c %c%c ", c_Faces[5], c_Rank[5], c_Faces[6], c_Rank[6]);
      }
    }
    else if (Trio[0] == 4 || Trio[0] == 5 || Trio [0] == 6){
      if (write_file == 1)
      {
        fprintf(write,"%c%c %c%c ", c_Faces[2], c_Rank[2], c_Faces[3], c_Rank[3]);
      } else
      {
        printf("%c%c %c%c ", c_Faces[2], c_Rank[2], c_Faces[3], c_Rank[3]);
      }
      while (j<3)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        }
      }
    }
    else if (Trio[0] == 3){
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[2], c_Rank[2]);
      } else
      {
        printf("%c%c ", c_Faces[2], c_Rank[2]);
      }
      while (j<3)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Trio[j]], c_Rank[Trio[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[6], c_Rank[6]);
      } else
      {
        printf("%c%c ", c_Faces[6], c_Rank[6]);
      }
    }
    break;
    case 3:
    if(Pair[0] != 2)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[2], c_Rank[2]);
      } else
      {
        printf("%c%c ", c_Faces[2], c_Rank[2]);
      }
      while (j<4)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
    }
    else if ( Pair[0] == 2 && Pair[2] != 4){
      while (j<2)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[4], c_Rank[4]);
      } else
      {
        printf("%c%c ", c_Faces[4], c_Rank[4]);
      }
      j = 2;
      while (j < 4)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
    }
    else if(Pair[0] == 2 ){
      while (j<4)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[6], c_Rank[6]);
      } else
      {
        printf("%c%c ", c_Faces[6], c_Rank[6]);
      }
    }
    break;
    case 2:
    if(Pair[0] == 5 || Pair[0] == 6 || Pair [0] == 7)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c %c%c %c%c ", c_Faces[2], c_Rank[2], c_Faces[3], c_Rank[3], c_Faces[4], c_Rank[4]);
      } else
      {
        printf("%c%c %c%c %c%c ", c_Faces[2], c_Rank[2], c_Faces[3], c_Rank[3], c_Faces[4], c_Rank[4]);
      }
      while (j<2)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
    }
    else if ( Pair[0] == 4){
      if (write_file == 1)
      {
        fprintf(write,"%c%c %c%c ", c_Faces[2], c_Rank[2], c_Faces[3], c_Rank[3]);
      } else
      {
        printf("%c%c %c%c ", c_Faces[2], c_Rank[2], c_Faces[3], c_Rank[3]);
      }
      while (j<2)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[6], c_Rank[6]);
      } else
      {
        printf("%c%c ", c_Faces[6], c_Rank[6]);
      }
    }
    else if(Pair[0] == 3 ){
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[2], c_Rank[2]);
      } else
      {
        printf("%c%c ", c_Faces[2], c_Rank[2]);
      }
      while (j<2)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c %c%c ", c_Faces[5], c_Rank[5], c_Faces[6], c_Rank[6]);
      } else
      {
        printf("%c%c %c%c ", c_Faces[5], c_Rank[5], c_Faces[6], c_Rank[6]);
      }
    }
    else if(Pair[0] == 2 ){
      while (j<2)
      {
        if (write_file == 1)
        {
          fprintf(write,"%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        } else
        {
          printf("%c%c ", c_Faces[Pair[j]], c_Rank[Pair[j]]);
          j++;
        }
      }
      if (write_file == 1)
      {
        fprintf(write,"%c%c %c%c %c%c ", c_Faces[4], c_Rank[4], c_Faces[5], c_Rank[5], c_Faces[6], c_Rank[6]);
      } else
      {
        printf("%c%c %c%c %c%c ", c_Faces[4], c_Rank[4], c_Faces[5], c_Rank[5], c_Faces[6], c_Rank[6]);
      }
    }
    break;
    case 1:
    j = 2;
    while (j<7)
    {
      if (write_file == 1)
      {
        fprintf(write,"%c%c ", c_Faces[j], c_Rank[j]);
        j++;
      } else
      {
        printf("%c%c ", c_Faces[j], c_Rank[j]);
        j++;
      }
    }
    break;
    default:
    break;
  }
}
//----------------------------------------------------------------------ChooseToPrint_End-------------------------------------------------------------//

//----------------------------------------------------------------------EMPATE-------------------------------------------------------------//
void MesmoTipoMao (int argc, int Compare1[],int Compare2[], int PokerHand, int SaveF, int SaveMao1[], int SaveMao2[], int S_Flush[],char *c_Faces, char *c_Rank, int mode){

  // Quando as duas maos sao do mesmo tipo, faz o desempate de acordo com o tipo identificado.
  // Esta função é utilizada nos modos -c, d3 e d4 e dx.
  // No modo dx, não imprime o restultado do desempate. A função apenas é chamada para termos estatisticos.

  int i=2;
  int b= 0;
  int sair = 0;
  int a= 0;
  int count = 0;
  int TA = 0;
  int TB = 0;
  int TC = 0;
  int TD = 0;
  int zero = 0;
  switch(PokerHand)
  {
    case 10:
    result = 0;
    if (write_file == 1 && mode !=4)
    {
      fprintf(write,"%d\n", result);
      return;
    } else if (mode !=4) {
      printf("%d\n", result);
    }
    break;
    case 1:
    while (i<=6){
      if (Compare1[i] > Compare2[i])
      {

        result = 1;
        if (write_file == 1 && mode !=4)
        {
          fprintf(write,"%d\n", result);
          return;
        }else if (mode !=4) {
          printf("%d\n", result);
        }
        return;
      }
      else if (Compare1[i] < Compare2[i])
      {
        result = 2;
        if (write_file == 1 && mode !=4)
        {
          fprintf(write,"%d\n", result);
          return;
        }else if (mode !=4) {
          printf("%d\n", result);
        }
        return;
      }
      else
      {
        zero = 0;
        result = 0;
        i++;
      }
    }
    if (write_file == 1 && mode !=4)
    {
      fprintf(write,"%d\n", zero);
      return;
    }else if (mode !=4) {
      printf("%d\n", zero);
    }
    return;
    break;
    case 9:
    if (Compare1[SaveMao1[1]] > Compare2[SaveMao2[1]]){

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;

    }else if(Compare1[SaveMao1[1]] < Compare2[SaveMao2[1]])
    {
      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 8:
    for ( i = 2; i < 7; i++)
    {
      if ((Compare1[i] != Compare1[SaveF]) && (sair == 0))
      {
        a = i;
        sair++;
      }
      if ((Compare2[i] != Compare2[FourKind[0]]) && (count == 0))
      {
        b = i;
        count++;
      }
    }
    if ((Compare1[SaveF] > Compare2[FourKind[0]]) || ((Compare1[SaveF] == Compare2[FourKind[0]]) && (Compare1[a] > Compare2[b]))){

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else if((Compare1[SaveF] < Compare2[FourKind[0]]) || ((Compare1[SaveF] == Compare2[FourKind[0]]) && (Compare1[a] < Compare2[b])))
    {
      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 7:
    if ((Compare1[SaveMao1[1]] > Compare2[SaveMao2[1]]) || ((Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) &&  (Compare1[SaveMao1[0]] > Compare2[SaveMao2[0]]))) {

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;

    }else if((Compare1[SaveMao1[1]] < Compare2[SaveMao2[1]]) || ((Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) &&  (Compare1[SaveMao1[0]] < Compare2[SaveMao2[0]])))
    {
      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 6:
    zero = 4;
    for ( i = 0; i < 5; i++)
    {
      if (Compare1[S_Flush[i]] > Compare2[Flush[i]]){

        result = 1;
        if (write_file == 1 && mode !=4)
        {
          fprintf(write,"%d\n", result);
          return;
        }else if (mode !=4) {
          printf("%d\n", result);
        }
        return;

      }else if(Compare1[S_Flush[i]] < Compare2[Flush[i]])
      {
        result = 2;
        if (write_file == 1 && mode !=4)
        {
          fprintf(write,"%d\n", result);
          return;
        }else if (mode !=4) {
          printf("%d\n", result);
        }
        return;

      }else
      {
        zero--;
      }
    }
    if(zero <= 0)
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 5:
    if (Compare1[SaveMao1[0]] > Compare2[SaveMao2[0]]){

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;

    }else if(Compare1[SaveMao1[0]] < Compare2[SaveMao2[0]])
    {
      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 4:
    for ( i = 2; i < 7; i++)
    {
      if (Compare1[i] !=   Compare1[SaveMao1[1]])
      {
        if (count == 0){
          TA = i;
          count++;
        }else if( count <2)
        {
          TB = i;
          count++;
        }
      }
    }
    count = 0;
    for ( i = 2; i < 7; i++)
    {
      if (Compare2[i] != Compare2[SaveMao2[1]])
      {
        if (count == 0){
          TC = i;
          count++;
        }else if (count<2)
        {
          TD = i;
          count++;
        }
      }
    }
    if ((Compare1[SaveMao1[1]] > Compare2[SaveMao2[1]])\
    || ((Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) &&  (Compare1[TA] > Compare2[TC]))\
    || ((Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) &&  (Compare1[TA] == Compare2[TC]) && (Compare1[TB] > Compare2[TD]))) {

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;

    }else if((Compare1[SaveMao1[1]] < Compare2[SaveMao2[1]])\
    || ((Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) &&  (Compare1[TA] < Compare2[TC]))\
    || ((Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) &&  (Compare1[TA] == Compare2[TC]) && (Compare1[TB] < Compare2[TD]))) {

      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 3:
    for ( i = 2; i < 7 && sair<2; i++)
    {
      if (Compare1[i] !=   Compare1[SaveMao1[0]] && Compare1[i] != Compare1[SaveMao1[1]])
      {
        a = i;
        sair++;
      }
      if (Compare1[i] !=   Compare1[SaveMao2[0]] && Compare1[i] != Compare1[SaveMao2[1]])
      {
        b = i;
        sair++;
      }
    }
    if ((Compare1[SaveMao1[0]] > Compare2[SaveMao2[0]]) \
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[SaveMao1[1]] > Compare2[SaveMao2[1]]))\
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) && (Compare1[a] > Compare2[b]))){

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;

    }else if ((Compare1[SaveMao1[0]] < Compare2[SaveMao2[0]]) \
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[SaveMao1[1]] < Compare2[SaveMao2[1]]))\
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[SaveMao1[1]] == Compare2[SaveMao2[1]]) && (Compare1[a] < Compare2[b]))){
      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
    case 2:
    for ( i = 2; i < 7 && sair <3; i++)
    {
      if (Compare1[i] !=   Compare1[SaveMao1[0]])
      {
        if (count == 0){
          TA = i;
          count++;
        }else if (count == 1)
        {
          TB = i;
          count++;
        } else
        {
          a = i;
        }
        sair++;
      }
    }
    count = 0;
    sair = 0;
    for ( i = 2; i < 7 && sair<3; i++)
    {
      if (Compare2[i] != Compare2[SaveMao2[0]])
      {
        if (count == 0){
          TC = i;
          count++;
        }else if (count == 1)
        {
          TD = i;
          count++;
        }
        else
        {
          b = i;
        }
        sair++;
      }

    }
    if ((Compare1[SaveMao1[0]] > Compare2[SaveMao2[0]])
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[TA] > Compare2[TC]))
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[TA] == Compare2[TC]) && (Compare1[TB] > Compare2[TD]))
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[TA] == Compare2[TC]) && (Compare1[TB] == Compare2[TD]) && (Compare1[a] > Compare2[b]))){

      result = 1;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;

    }else if ((Compare1[SaveMao1[0]] < Compare2[SaveMao2[0]])
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[TA] < Compare2[TC]))
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[TA] == Compare2[TC]) && (Compare1[TB] < Compare2[TD]))
    || ((Compare1[SaveMao1[0]] == Compare2[SaveMao2[0]]) && (Compare1[TA] == Compare2[TC]) && (Compare1[TB] == Compare2[TD]) && (Compare1[a] < Compare2[b]))){
      result = 2;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      }else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }else
    {
      result = 0;
      if (write_file == 1 && mode !=4)
      {
        fprintf(write,"%d\n", result);
        return;
      } else if (mode !=4) {
        printf("%d\n", result);
      }
      return;
    }
    break;
  }
  return;
}
//----------------------------------------------------------------------EMPATE_End-------------------------------------------------------------//

//----------------------------------------------------------------------GuardaVect-------------------------------------------------------------//
int Guarda_Vect (int prox, int argc, int PokerHand, int Faces[]){
  int Four = 0;                                                       // De acordo com o tipo de m�o, faz a salvaguarda da posi��o onde se encontra a primeira carta que define o tipo de m�o
  int SaveP = 0;                                                      // Exemplo: no caso de trio, vai ficar salvaguardado a primeira posi��o do vetor Trio[]
  int SaveT = 0;
  int sair = 0;
  int i = 0;
  int j = 0;
  switch (PokerHand)
  {
    case 8:
    Four = FourKind[0];
    return Four;
    break;
    case 7:
    if(Trio[5] != 0 && (Pair[1] - Pair[0] != 1) && (Pair[3] - Pair[2] != 1))
    {
      if (prox == 0){
        SaveT = Trio[0];
        return SaveT;
      }else
      {
        SaveP = Trio[3];
        return SaveP;
      }
    }
    else if (Pair[1] - Pair[0] != 1)
    {
      if (prox == 0){
        SaveT = Trio[0];
        return SaveT;
      }else
      {
        SaveP = Pair[2];
        return SaveP;
      }
    }
    else
    {
      for (i = 0; i < 5 && sair<1; i++)
      {
        if (Faces[Trio[i]] == Faces[Trio[i+2]])
        {
          j= i;
          sair++;
        }
      }
      if (prox == 0){
        SaveT = Trio[j];
        return SaveT;
      }else
      {
        SaveP = Pair[0];
        return SaveP;
      }
    }
    break;
    case 5:
    case 9:
    if (prox == 0){
      SaveT = StraightFlush[0];
      return SaveT;
    }else
    {
      SaveP = Straight[0];
      return SaveP;
    }
    break;
    case 4:
    if (prox == 0){
      SaveT = Trio[0];
      return SaveT;
    }else
    {
      SaveP = 0;
      return SaveP;
    }
    break;
    case 3:
    if (prox == 0){
      SaveT = Pair[2];
      return SaveT;
    }else
    {
      SaveP = Pair[0];
      return SaveP;
    }
    break;
    case 2:
    if (prox == 0){
      SaveT = 0;
      return SaveT;
    }else
    {
      SaveP = Pair[0];
      return SaveP;
    }
    break;

    default:
    break;
  }
  return 0;
}
//----------------------------------------------------------------------GuardaVect_End------------------------------------------------------------//

//----------------------------------------------------------------------OrganizaArgvA1-------------------------------------------------------------//
void OrganizaArgvA1 (int argc, int Faces[], char *c_Faces, char *c_Rank){
  int i = 0;                                                        // Nos caso em que o As é a carta com menor valor, troca-se a posiçao das cartas no vetor argv para que este fique em ultimo.
  char aux[1][2] = {0};
  if ( argc == 9){
    argc = 7;
  }
  for (i =0; i < 14; i++)
  {
    if (Faces[i]==1 && argc ==7)
    {
      aux[0][0] = c_Faces[2];
      aux[0][1] = c_Rank[2];
      c_Faces[2] = c_Faces[3];
      c_Rank[2] = c_Rank[3];
      c_Faces[3] = c_Faces[4];
      c_Rank[3] = c_Rank[4];
      c_Faces[4] = c_Faces[5];
      c_Rank[4] = c_Rank[5];
      c_Faces[5] = c_Faces[6];
      c_Rank[5] = c_Rank[6];
      c_Faces[6] = c_Faces[7];
      c_Rank[6] = c_Rank[7];
      c_Faces[7] = c_Faces[8];
      c_Rank[7] = c_Rank[8];
      c_Faces[8] = aux[0][0];
      c_Rank[8] = aux[0][1];
    }
    if (Faces[i]==1 && argc ==5)
    {
      aux[0][0] = c_Faces[2];
      aux[0][1] = c_Rank[2];
      c_Faces[2] = c_Faces[3];
      c_Rank[2] = c_Rank[3];
      c_Faces[3] = c_Faces[4];
      c_Rank[3] = c_Rank[4];
      c_Faces[4] = c_Faces[5];
      c_Rank[4] = c_Rank[5];
      c_Faces[5] = c_Faces[6];
      c_Rank[5] = c_Rank[6];
      c_Faces[6] = aux[0][0];
      c_Rank[6] = aux[0][1];
    }
  }
  return;
}
//----------------------------------------------------------------------OrganizaArgvA1_End-------------------------------------------------------------//

void Copia_argv (int argc, char **argv, char *c_Faces, char*c_Rank){

  // Esta função foi acrescentada após a entrega do projeto intermédio, para corrigir eventuais dificuldades que encontramos nesta fase final.
  // Esta função copia o valor das cartas para a malloc c_Faces e os naipes para a malloc c_Rank.
  // Apenas é chamada no modo linha comando (-c).

  for (int i = 2; i <= argc+1; i++)
  {
    c_Faces[i] = argv[i][0];
    c_Rank[i] = argv[i][1];
  }
}

void ReOrganizaArgvA1 (int argc, int Faces[], char *c_Faces, char *c_Rank, int change){

  /* Esta função reorganiza as mallocs c_Faces e c_Rank, para os casos em que o As tinha ficado com valor 1, ou seja nas cartas inseridas, existia um STRAIGHT sendo o As a carta de menor valor,
  porém estava também presente uma mao maior que esse STRAIGHT em que o As nao seria a carta que valia menos.*/

  int i = 0;
  char aux[1][2] = {0};

  if (argc == 9){
    argc = 7;
  }
  for (i =0; i < 14; i++)
  {
    if (Faces[i]==1 && argc ==5 )
    {
      aux[0][0] = c_Faces[6];
      aux[0][1] = c_Rank[6];
      c_Faces[6] = c_Faces[5];
      c_Rank[6] = c_Rank[5];
      c_Faces[5] = c_Faces[4];
      c_Rank[5] = c_Rank[4];
      c_Faces[4] = c_Faces[3];
      c_Rank[4] = c_Rank[3];
      c_Faces[3] = c_Faces[2];
      c_Rank[3] = c_Rank[2];
      c_Faces[2] = aux[0][0];
      c_Rank[2] = aux[0][1];
      Faces[i] = 14;
    }
    if (Faces[i]==1 && argc ==7 )
    {
      aux[0][0] = c_Faces[8];
      aux[0][1] = c_Rank[8];
      c_Faces[8] = c_Faces[7];
      c_Rank[8] = c_Rank[7];
      c_Faces[7] = c_Faces[6];
      c_Rank[7] = c_Rank[6];
      c_Faces[6] = c_Faces[5];
      c_Rank[6] = c_Rank[5];
      c_Faces[5] = c_Faces[4];
      c_Rank[5] = c_Rank[4];
      c_Faces[4] = c_Faces[3];
      c_Rank[4] = c_Rank[3];
      c_Faces[3] = c_Faces[2];
      c_Rank[3] = c_Rank[2];
      c_Faces[2] = aux[0][0];
      c_Rank[2] = aux[0][1];
      Faces[i] = 14;
    }
  }
  return;
}

void ChangeBack(int Faces[], int change){

  /* Esta função reorganiza o vetor Faces, para os casos em que o As tinha ficado com valor 1, ou seja nas cartas inseridas, existia um STRAIGHT sendo o As a carta de menor valor,
  porém estava também presente uma mao maior que esse STRAIGHT em que o As nao seria a carta que valia menos.*/

  int PokerHand = 1, i;

  for (i = 0; i < 10; i++)
  {
    if (VerificaHand[i] != 0)
    {
      PokerHand = VerificaHand[i];
    }
  }

  if ((PokerHand != 9 && PokerHand != 5) && change == 1)
  {

    for (i =0; i < 14; i++)
    {
      if (Faces[i]==1)
      {
        Faces[i] = 14;
      }
    }
  }
}
