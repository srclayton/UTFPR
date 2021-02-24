//7. Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e dois
//números reais. O programa deve retornar o resultado da operação recebida sobre estes dois//
//números.

#include<stdio.h>
int main(){
  int a,b;
  char op;
  printf("Digite a operação (+, -, / ou *) \n");
  scanf("%c", &op);
  printf("Digite os valores\n");
  scanf("%d %d", &a, &b);

  if(op=='+')
    printf("%d + %d = %d.", a,b, a+b);
  else if(op=='-')
    printf("%d - %d = %d", a,b, a-b );
  else if(op=='/')
    printf("%d / %d = %d", a,b, a/b);
  else
    printf("%d * %d = %d",a,b, a*b );
  return 0;
}
