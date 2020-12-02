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
    printf("Z");
    sleep(1);
    printf("Z");
    sleep(1);
    printf("Z\n");
  }
  else if (metodo == 1 && timeSimu > 12){
    printf("O caixeiro descansou na cidade %d\n", Z);
    pode = 0;
    sleep(1);
    printf("Z");
    sleep(1);
    printf("Z");
    sleep(1);
    printf("Z\n");
  }

  return pode;
}


int andar(int Matriz[L][C], int cidade_inicial)
{

  int percurso[L];
  for (int x = 0; x<L; x++){percurso[x] = -1;}

  int len_atual = 0, distancia_total = 0;
  percurso[0] = cidade_inicial;

  for(;;){

    if (len_atual == (L-1)){break;}

    int pode = 0;

    int cidade_mais_proxima[2]; cidade_mais_proxima[1] = 2000;

    for (int l = 0; l < L; l++){
      for (int c = 0; c < C; c++){
        for (int per = 0; (percurso[per] != -1) || (per < L); per++)
          if (Matriz[l][c]!= 0){
            if (len_atual == 0){
              if (Matriz[l][c] < cidade_mais_proxima[1]){
                cidade_mais_proxima[1] = Matriz[l][c];
                if (l == percurso[len_atual]){cidade_mais_proxima[0] = l;}
                if (c == percurso[len_atual]){cidade_mais_proxima[0] = c;}
              }
            }else if((l != percurso[per]) && (c != percurso[per])){
              if (Matriz[l][c] < cidade_mais_proxima[1]){
                cidade_mais_proxima[1] = Matriz[l][c];
                if (l == percurso[len_atual]){cidade_mais_proxima[0] = l;}
                if (c == percurso[len_atual]){cidade_mais_proxima[0] = c;}
              }
            }
          }
        }
      }

      pode = veri(distancia_total, cidade_mais_proxima[1], cidade_mais_proxima[0]);

      if (pode == 1){
      len_atual ++;
      distancia_total += cidade_mais_proxima[1];
      percurso[len_atual] = cidade_mais_proxima[0];
      }else{
        distancia_total = 0;
        len_atual ++;
        distancia_total += cidade_mais_proxima[1];
        percurso[len_atual] = cidade_mais_proxima[0];
      }
  }

  int pode = 0, cidade_mais_proxima[2];

  cidade_mais_proxima[0] = cidade_inicial;
  cidade_mais_proxima[1] = Matriz[percurso[len_atual]][cidade_mais_proxima[0]];

  pode = veri(distancia_total, cidade_mais_proxima[1], cidade_mais_proxima[0]);

  printf("O trajeto terminou!\nO caixeiro pelas cidades:\n");
  for (int i = 0; i < 30; i++){
    printf("%d -> ", percurso[i]);
  }
  printf("%d\n", cidade_inicial);

  return 1;
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
}
