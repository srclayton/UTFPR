#include<stdio.h>
#include<string.h>
typedef struct fichaPac{
  int codigo;
  char nome[35];
  int idade;
  char sexo;
  float altura;
  float peso;
} F_paciente;

int menu();
void cadastraPac();

int main() {
  int input;
  input = menu();
  if (input == 1) {
    cadastraPac();
  }


  return 0;
}
void cadastraPac(){
  int i=0, input;
  F_paciente fichapac;

    fflush(stdin);
    __fpurge(stdin);
    printf("Digite o nome\n" );
    fgets(fichapac.nome, 35, stdin);
    printf("Digite o sexo\n");
    scanf("%c\n",&fichapac.sexo );
    fflush(stdin);
    __fpurge(stdin);
    printf("Digite o codigo do paciente.\n");
    scanf("%d\n",&fichapac.codigo );
    printf("Digite a idade\n");
    scanf("%d\n",&fichapac.idade );
    printf("Digite a altura\n");
    scanf("%f\n",&fichapac.altura );
    printf("Digite o peso\n");
    scanf("%f\n",&fichapac.peso );
// role do maloc e realoc / faz um molloc com 1, se desejar mais cadastros realloc TAM++ e já era, porem estou com preguiça agora.
    fputs(fichapac.nome, stdout);

}
int menu(){
int input;
  printf("Digite a opção desejada\n");
  printf("1- Cadastrar pacientes\n");
  printf("2- Exibir o nome do paciente com maior peso\n");
  printf("3- Exibir nome e idade das pessoas que estejam acima de seu peso ideal\n");
  printf("4- Exibir o nome das pessoas que estejam abaixo de seu peso ideal, mostrando ainda o peso que essas pessoas deverão alcançar para atingir esse peso ideal\n");
  scanf("%d\n",&input);
  return input;
}
