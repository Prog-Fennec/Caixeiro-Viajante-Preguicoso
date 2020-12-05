#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define L 30
#define C 30

int metodo;

int veri(int X, int Y, int Z)
{
  //X = distância total, Y = distância até a cidade mais próxima, Z é o número da cidade atual
  int pode = 1;

  int distSimu = X + Y;
  float timeSimu = (X + Y)/90;

  if (metodo == 0 && distSimu > 1000){
    printf("O caixeiro descansou na cidade %d\n", Z);
    pode = 0;
    sleep(1);
    printf("ZZZ\n");
  }
  else if (metodo == 1 && timeSimu > 12){
    printf("O caixeiro descansou na cidade %d\n", Z);
    pode = 0;
    sleep(1);
    printf("ZZZ\n");
  }

  return pode;
}


void andar(int Matriz[L][C], int cidade_inicial){

  int percurso[L];
  for (int x = 0; x<L;x++){percurso[x]=-1;}
  percurso[0] = cidade_inicial;

  int CMP[2];

  int vai = 0, contador = 0, pode, dist = 0;

  int CP[L]; for (int n = 0; n < L; n++){CP[n] = 0;}
  CP[cidade_inicial] = 1;
  
  while (1){ 

    CMP[1] = 2000;

    for (int c =  0; c<C; c++) {

      if (CP[c] == 0){
        if (Matriz[percurso[contador]][c] < CMP[1]){
          CMP[1] = Matriz[percurso[contador]][c];
          CMP[0] = c;
        }
      }

    }

  pode = veri(dist, CMP[1], percurso[contador]);
  contador++;
  percurso[contador] = CMP[0];
  if (pode == 0){dist = 0;}
  dist += CMP[1];
  CP[CMP[0]] = 1;
  if (contador == L-1){break;}

  }

  pode = veri(dist, CMP[1], percurso[contador]);
  printf("A jornada do caixeiro preguiçoso acabou!\nEle passou pelas cidades:\n");
  for (int n = 0; n < L; n++){
    printf("%d -> ", percurso[n]);
  }
  printf("%d\n", cidade_inicial);
}


int main()
{
  int DIST[L][C], CIDADE[L], cidadeInicial;

//Cidades e Diagonal Principal da Matriz
  for(int i = 0; i < L; i++)
  {
    CIDADE[i] = i;
    DIST[i][i] = 0; //Valores da diagonal principal = 0
  }

//Acima da Diagonal Princpal
  for(int l = 0; l < L; l++)
  {
    for(int c = l + 1; c < C; c++)
    {
      printf("Distancia entre as cidades %d e %d:\n", CIDADE[l], CIDADE[c]);
      scanf("%d", &DIST[l][c]); //Receber distancias
    }
  }

//Printar e espelhar a parte de cima da matriz pra parte de baixo
  for(int l = 0; l < L; l++)
  {
    for(int c = 0; c < C; c++)
    {
      DIST[c][l] = DIST[l][c]; //Espelhar
      //printf("%d ", DIST[c][l]); //Printar a matriz caso queira
    }
    //printf("\n"); //Printar a matriz caso queira
  }

//Cidade Inicial
  printf("\nEm qual cidade voce ira comecar?\n");
  scanf("%d", &cidadeInicial);
  cidadeInicial = CIDADE[cidadeInicial];

//Metodo
  printf("\nQual metodo voce vai usar?\n");
  printf("[0] Distancia\n");
  printf("[1] Tempo\n");
  scanf("%d", &metodo);

  andar(DIST, cidadeInicial);

}
