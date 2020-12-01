#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int metodo;

int veri(int X, int Y, int Z){
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


int andar(int Matriz[30][30], int cidade_inicial){
  
  int percurso[30];
  for (int x = 0; x<30; x++){percurso[x] = -1;}
  
  int len_atual = 0, distancia_total = 0;
  percurso[0] = cidade_inicial;

  for(;;){

    if (len_atual == 29){break;}

    int pode = 0;
    
    int cidade_mais_proxima[2]; cidade_mais_proxima[1] = 2000;

    for (int l = 0; l < 30; l++){
      for (int c = 0; c < 30; c++){
        for (int per = 0; (percurso[per] != -1) || (per < 30); per++)
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


int main(){}

