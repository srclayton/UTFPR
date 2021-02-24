#include<stdio.h>
typedef struct boleto {
  int codigo;
  float valor;
  char tipo;
} Boleto;

int main(){
  int calc_receita(Boleto input[]);
  Boleto input[10];
  int i=0;
  float receita;
  while ( i < 10) {
      printf("Digite o codigo\n");
      scanf("%d",&input[i].codigo);
      printf("Digite o valor\n");
      scanf("%f",&input[i].valor);
      printf("Digite o tipo de despesa\n");
      fflush(stdin);
    //__fpurge(stdin);
      scanf("%c",&input[i].tipo);
    i++;
  }
  receita = calc_receita(input);
  printf("RECEITA: %f \n",receita);
  return 0;
}

int calc_receita(Boleto input[]){
  float r_valor=0, d_valor=0;
  for (int i = 0; i < 10; i++) {
    if (input[i].tipo=='r' || input[i].tipo=='R')
      r_valor = r_valor + input[i].valor;
    else
      d_valor =  d_valor +input[i].valor;
  }
  return r_valor - d_valor;
}
