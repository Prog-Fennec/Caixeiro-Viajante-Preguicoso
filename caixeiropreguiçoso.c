/*
função veri{
5 - somar a próxima distância à distância total e guardar em uma variavel (int)
6 - dividir a distância da parte 5 por 90 para obter o tempo da viagem caso o próximo caminho seja percorrido, guardar em uma variável (float)
7 - Verificar se a soma das distancias + a próxima distância passa de 1000 ou se o tempo total + próximo tempo passa de 12. Caso uma das variáveis for ultrapassar o limite printar no console que o caixeiro descansará na cidade atual
}
*/

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
