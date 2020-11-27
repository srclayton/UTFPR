#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void aplicaRegras(int matriz[TAM][TAM]);
void criaImagem(int matriz[][TAM], char escolha);
void printaMatriz(int matriz[][TAM]);

int main()
{
    char escolha;

    //MENU DE OPÇÕES
    printf("=================================\n");
    printf("   JOGO DA VIDA - JOHN CONWAY\n");
    printf("=================================\n");
    printf("Escolha uma opção: \n\n");
    printf("1. Vidas paradas\n   a) vida eterna 1 \n   b) vida eterna 2\n\n");
    printf("2. Osciladores\n   c) blinker \n   d) sapo\n\n");
    printf("3. Naves espaciais\n   e) glider \n   f) lightweigth spaceship\n\n");
    printf("R: ");
    scanf("%c", &escolha);
    system("clear");

    //IMPEDE O USUARIO DE ESCOLHER UMA OPÇÃO INVALIDA.
    while(escolha < 65 || escolha > 70 && escolha < 97 || escolha > 102)
    {
        printf("\n=================================\n");
        printf("        Opcao Invalida!\n Favor escolher uma nova opcao!\n");
        printf("=================================\n");
        printf("1. Vidas paradas\n   a) vida eterna 1 \n   b) vida eterna 2\n\n");
        printf("2. Osciladores\n   c) blinker \n   d) sapo\n\n");
        printf("3. Naves espaciais\n   e) glider \n   f) lightweigth spaceship\n\n");
        printf("R: ");
        scanf("%c", &escolha);
        system("clear");
    }

    //PREENCHE A MATRIZ COM ZEROS.
    int i, j;
    int matriz[TAM][TAM], matrizCopia[TAM][TAM];

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
            matriz[i][j] = 0;
    }

    criaImagem(matriz, escolha);
    printaMatriz(matriz);
    system("clear");
    aplicaRegras(matriz);

    return 0;
}

/*============================================================================*/

/** Esta função aplica as regras do jogo informadas no artigo
 *  cedido pelos professores, na matriz.
 *
 *  Parâmetros: matriz[TAM][TAM]: Matriz de dados.
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera a matriz. **/

void aplicaRegras(int matriz[TAM][TAM])
{
    int i, j, somaVizinhos, matrizCopia[TAM][TAM];

    //PREENCHE A MATRIZ COPIA COM ZEROS
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matrizCopia[i][j] = 0;
        }
    }

    //PERCORRE A MATRIZ ORIGINAL PARA APLICAR AS REGRAS DE CONWAY, E ATUALIZA A PROXIMA GERAÇÃO NA MATRIZ COPIA
    for(i = 1; i < TAM-1; i++)
    {
        for(j = 1; j < TAM-1; j++)
        {
            if(matriz[i][j] == 1)
            {
                somaVizinhos = matriz[i-1][j] + matriz[i-1][j+1] + matriz[i][j+1] + matriz[i+1][j+1] + matriz[i+1][j] + matriz[i+1][j-1] + matriz[i][j-1] + matriz[i-1][j-1];

                if(somaVizinhos < 2)
                    matrizCopia[i][j] = 0;

                else if(somaVizinhos > 3)
                    matrizCopia[i][j] = 0;

                else if(somaVizinhos == 2 || somaVizinhos == 3)
                    matrizCopia[i][j] = 1;

            }

            else if(matriz[i][j] == 0)
            {
                somaVizinhos = matriz[i-1][j] + matriz[i-1][j+1] + matriz[i][j+1] + matriz[i+1][j+1] + matriz[i+1][j] + matriz[i+1][j-1] + matriz[i][j-1] + matriz[i-1][j-1];

                if(somaVizinhos == 3)
                    matrizCopia[i][j] = 1;
            }
        }
    }

    //ATUALIZA MATRIZ ORIGINAL COM A REGRA APLICADA
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j] = matrizCopia[i][j];
        }
    }

    system("cls");
    printaMatriz(matriz);
    sleep(1);
    aplicaRegras(matriz);
}

/*============================================================================*/

/** Esta função cria a imagem da opção escolhida na matriz.
 *
 *  Parâmetros: matriz[][TAM]: Matriz de dados.
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera a Matriz. **/

void criaImagem(int matriz[TAM][TAM], char escolha)
{
    if(escolha == 'a' || escolha == 'A')
    {
        matriz[4][4] = 1;
        matriz[4][5] = 1;
        matriz[5][4] = 1;
        matriz[5][5] = 1;
    }

    else if(escolha == 'b' || escolha == 'B')
    {
        matriz[4][4] = 1;
        matriz[5][5] = 1;
        matriz[5][6] = 1;
        matriz[4][7] = 1;
        matriz[3][5] = 1;
        matriz[3][6] = 1;
    }

    else if(escolha == 'c' || escolha == 'C')
    {
        matriz[4][4] = 1;
        matriz[4][5] = 1;
        matriz[4][6] = 1;
    }

    else if(escolha == 'd' || escolha == 'D')
    {
        matriz[4][4] = 1;
        matriz[4][5] = 1;
        matriz[4][6] = 1;
        matriz[3][5] = 1;
        matriz[3][6] = 1;
        matriz[3][7] = 1;
    }

    else if(escolha == 'e' || escolha == 'E')
    {
        matriz[5][3] = 1;
        matriz[4][2] = 1;
        matriz[3][2] = 1;
        matriz[3][3] = 1;
        matriz[3][4] = 1;
    }

    else if(escolha == 'f' || escolha == 'F')
    {
        matriz[5][3] = 1;
        matriz[4][3] = 1;
        matriz[3][3] = 1;
        matriz[2][4] = 1;
        matriz[5][4] = 1;
        matriz[5][5] = 1;
        matriz[5][6] = 1;
        matriz[4][7] = 1;
        matriz[2][7] = 1;
    }
}

/*============================================================================*/

/** Esta função desenha a matriz na tela.
 *
 *  Parâmetros: matriz[TAM][TAM]: Matriz de dados.
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera a matriz. **/

void printaMatriz(int matriz[TAM][TAM])
{
    int i, j;
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            if(matriz[i][j] == 1)
                printf(" O ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}
