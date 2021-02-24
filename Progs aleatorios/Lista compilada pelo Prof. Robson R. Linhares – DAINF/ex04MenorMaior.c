//6. Fazer um programa que recebe 3 valores não inteiros do usuário e mostra o maior deles, o
//menor deles e o valor intermediário.

#include<stdio.h>
int main(){
  int a,b,c;
  printf("Digite os valores:\n");
  scanf("%d %d %d",&a, &b, &c);
  if(a>b && a>c)
    if(b>c)
      printf("%d É maior, %d é o intermediário e o %d é o menor\n", a, b, c );
    else
      printf("%d É maior, %d é o intermediário e o %d é o menor\n", a, c, b );

  else if(b>a && b>c)
    if(a>c)
      printf("%d É maior, %d é o intermediário e o %d é o menor\n", b, a, c );
    else
      printf("%d É maior, %d é o intermediário e o %d é o menor\n", b, c, a );
  else if(c>a && c>b)
    if(a>b)
      printf("%d É maior, %d é o intermediário e o %d é o menor\n", c, a, b );
    else
      printf("%d É maior, %d é o intermediário e o %d é o menor\n", c, b, a );
  return 0;
}
