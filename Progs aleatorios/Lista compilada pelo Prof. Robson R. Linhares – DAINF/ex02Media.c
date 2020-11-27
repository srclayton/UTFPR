//2. Fazer um programa para receber 3 valores inteiros do usuário e mostrar a sua média (que
//pode não ser inteira). 

#include<stdio.h>
int main(){
  float n1,n2,n3;
  printf("informe os 3 valores\n");
  scanf("%f %f %f",&n1, &n2, &n2);
  float media= (n1+n2+n3)/3;
  printf("%.2f", media);
  return 0;
}
