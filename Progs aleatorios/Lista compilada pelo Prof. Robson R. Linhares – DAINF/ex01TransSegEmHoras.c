//1. Fazer um programa para
//a. receber do usuário um tempo em segundos, correspondente à duração de um evento
//qualquer (por ex. jogo de futebol)
//b. calcular e mostrar ao usuário o tempo equivalente em horas, minutos e segundos
#include<stdio.h>
int main(){
  int seg,min,hr,aux;
  printf("Digite o tempo em seg.\n");
  scanf("%d",&seg);
  hr = seg/3600;
  aux= seg%3600;
  min= aux/60;
  seg= aux%60;
  printf("%d horas %d minutos e %d segundos\n",hr, min,seg);
  return 0;
}
