#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void code(char string[], int vetor_string[],int tam);
void decode (int input[], int tam);
int main(){
    int choice, tam, *input_char;
    printf("Digite '1' para codificar ou '2' para decodificar.\n");
    scanf("%d", &choice);
    if(choice == 1){
        char input[300];
        __fpurge(stdin);
        printf("\nDigite a frase\n");
        __fpurge(stdin);
        fgets(input, 300, stdin);
        input[ strlen(input) -1]= '\0';
        tam = strlen(input); // Pego o tamanho da frase
        input_char= malloc (tam * sizeof(int)); // Crio um vetor com o tamanho da string
        for(int i=0; i <= tam; i++)  //Copiando a frase em um vetor
        input_char[i] = input[i];
        code(input, input_char, tam);
        free(input_char);
    }
    else
    {
        fflush(stdin);
        // __fpurge(stdin);
        printf("Quantos valores serão decodificados ?");
        scanf("%d", &tam);
        input_char= malloc (tam * sizeof(int));// Realizo o malloc com o tamanho exato de numeros a serem verificados
        printf("Digite os valores:\n");
        for(int i=0; i < tam; i++)
        scanf("%d", &input_char[i]);// leio os mesmos.
        for(int i=0; i < tam; i++)
        //printf("| %d |", input_char[i]);
        decode(input_char, tam);
        free(input_char);
    }
    return 0;
}

void code (char string[], int vetor_string[], int tam){
    int bin[8], i, one=0, aux=0,dec=0;
    for(int j=0; j < tam; j++){
        for (i = 7; i >= 0; i--){       //Binariza o carcter.
            if (vetor_string[j] % 2 == 0)
                bin[i] = 0;
            else{
                bin[i] = 1;
                one++;
            }
            vetor_string[j] = vetor_string[j] / 2;
        }
        if(one % 2 != 0){ //Corrige o valor binario mais a esquerda.
            bin[0]=1;
        }
        for(i=0; i<=7; i++){ //Valor corrido em um int...
            aux = aux * 10 + bin[i];
        }
	dec=0;
        for(i = 0; aux > 0; i++){// Atualiza seu valor decimal.
            dec = dec + pow(2, i) * (aux % 10);
            aux = aux / 10;
        }
        one=0;
        /*printf("|%c|", string[j]);
        for(i=0; i < 8; i++)
        printf("%d", bin[i]);
        printf("\n"); */
        vetor_string[j]= dec;
    }
    printf("Mensagem de entrada:\n%s", string);
    printf("\nMensagem codificada:\n");
    for(i=0; i<tam; i++)
    printf("| %d |", vetor_string[i]);
}
void decode (int input[], int tam){
    int bin[8], i;
    char *output;
    output=  malloc(tam*sizeof(char));
    for(int i=0; i<tam; i++){
        output[i] = input[i];
    }
    for(int j=0; j < tam; j++){
        for( i = 7; i>=0 ; i--){ //Binariza o valor
            if(input[j] % 2 == 0)
                bin[i] = 0;
            else
                bin[i] = 1;
            input[j] = input[j] / 2;
        }
        if(bin[0] == 1)
        bin[0] = 1;
        //transformar em DECIMAL, ja retirei o primeiro numero mais a esquerda, so falta trans. papa dec
          int decimal=0, aux;
        for(int i=0; i<8;i++){
          aux =  bin[i] * (pow(2,i));
          decimal+=aux;
         //printf("\n %d = %d *(%d^%d) \n", aux, bin[i], 2,i);
        }
        printf("%d\n", decimal );
        output[j]=decimal;
    }
    printf("\n%s", output);
}
