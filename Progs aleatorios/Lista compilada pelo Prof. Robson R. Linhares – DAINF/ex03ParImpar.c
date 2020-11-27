//4. Fazer um programa para ler um número do usuário e determinar se este número é par ou não
//par.

#include<stdio.h>
int main(){
  int num;
  printf("Digite o numero:\n");
  scanf("%d", &num);
  if (num % 2 == 0)
    printf("%d É par\n", num);
  else
    printf("%d É impar\n",num);
  return 0;
}
