#ifndef Linha_Comando_INCLUDED
#define Linha_Comando_INCLUDED

void CincoCartas (int, int[],char *,char *);
void DezCartas ( int, int [],char *,char *, int);
void SeteCartas (int, int [],char *,char *, int, int);
void NoveCartas(int,  int[],char *,char *, int);
void TipoDeMao(int, int[],char *,char *);
void OrganizaFacesString(int,char *,char *);
void OrganizaNaipesString(int,char *,char *);
void OrganizaNaipesString2(int,char *,char *);
void OrganizaFacesPosNaipesString(int,char *,char *);
void OrganizaArgvA1 (int , int [],char *,char *);
void ChooseToPrint (int,int, int [],char *,char *);
void MesmoTipoMao (int, int[], int[], int, int, int[], int[], int[],char *,char *, int);
void ConverteFaces(int, int [],char *,char *);
void OrganizaFaces(int,int[],char *,char *);
void ReOrganizaFaces(int, int[]);
void Copia_argv (int, char **, char*, char*);
void ChangeBack(int[], int);
void ReOrganizaArgvA1 (int , int [], char *, char *, int);
int Guarda_Vect (int, int, int, int[]);

#endif
