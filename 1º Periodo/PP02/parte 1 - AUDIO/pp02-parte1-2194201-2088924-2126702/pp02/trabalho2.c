/*============================================================================*/
/* IF61C - TRABALHO 2                                                         */
/*----------------------------------------------------------------------------*/
/* Autores: LUCAS GOMES SANTANA | MATEUS DE MATOS LEAL | CLAYTON SILVA DA ROCHA */
/*============================================================================*/

#include <stdlib.h>
#include <math.h>

#include "trabalho2.h"

/** Altera o ganho do áudio, de acordo com o sinal.
 *  Multiplica cada amostra pelo parâmetro ganho dado.
 *
 *  Parâmetros: double* dados: vetor de dados.
 *             unsigned long n_amostras: numero de amostras no vetor.
 *             double ganho: modificador do ganho (volume).
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera o vetor. */

void mudaGanho (double* dados, unsigned long n_amostras, double ganho)
{
    int i;

    for (i = 0; i < n_amostras; i++)
        dados[i] *= ganho;
}

/*============================================================================*/

/** Esta função adiciona “estalos” periódicos a um sinal.
 *  O ruído começa com o valor 1 na posição 0, e vai intercalando
 *  1 e -1 em um intervalo dado.
 *
 *  Parâmetros: double* dados: vetor de dados.
 *             unsigned long n_amostras: numero de amostras no vetor.
 *             unsigned short intervalo: o número de amostras entre dois
 *                                       pontos de ruído é intervalo-1.
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera o vetor. **/

void ruidoPeriodico (double* dados, unsigned long n_amostras, unsigned short intervalo)
{
    int i, j = 0;


    for (i = 0; i < n_amostras; i = i + intervalo)
    {
        j++;

        if (j % 2 != 0)
            dados[i] = -1;
        else
            dados[i] = 1;
    }
}

/*============================================================================*/

/** Esta função recebe um sinal com “estalos” (do tipo gerado pela
 *  função ruidoPeriodico) e produz uma versão aproximada do sinal original.
 *  Para isso, usa um filtro da mediana de largura 3:
 *  cada amostra é substituída pela mediana dos valores em uma vizinhança que
 *  inclui a amostra, sua antecessora e sua sucessora.
 *
 *  Parâmetros: double* dados: vetor de dados.
 *             unsigned long n_amostras: numero de amostras no vetor.
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera o vetor. */

void removeRuido (double* dados, unsigned long n_amostras)
{
    int i;
    long int amostras;
    double mediana, original = dados[0], min, max;

    amostras = n_amostras - 1;

    for (i = 1; i < amostras; i++)
    {
        min = original; // DEFINE O MENOR VALOR

        if (dados[i] < original && dados[i] < dados[i+1])
            min = dados[i];
        if (dados[i+1] < original && dados[i+1] < dados[i])
            min = dados[i+1];

        max = original; // DEFINE O MAIOR VALOR

        if (dados[i] > original && dados[i] > dados[i+1])
            max = dados[i];
        if (dados[i+1] > original && dados[i+1] > dados[i])
            max = dados[i+1];

        // DEFINE A MEDIANA
        if ((min == dados[i] && max == dados[i+1]) || (min == dados[i+1] && max == dados[i]))
            mediana = original;
        else if ((min == original && max == dados[i]) || (min == dados[i] && max == original))
            mediana = dados[i+1];
        else
            mediana = dados[i];

        original = dados[i];
        dados[i] = mediana;
    }
}

/*============================================================================*/

/** Esta função simula uma sub-amostragem do sinal.
 *  Substitui cada grupo de n_constantes amostras pelo valor
 *  da primeira amostra do grupo.
 *
 *  Parâmetros: double* dados: vetor de dados.
 *             unsigned long n_amostras: numero de amostras no vetor.
 *             unsigned short n_constantes: largura de cada "degrau".
 *
 *  Valor de Retorno: NENHUM, é um procedimento que já altera o vetor. **/

void simulaSubAmostragem (double* dados, unsigned long n_amostras, unsigned short n_constantes)
{
    unsigned long i, j;

    for (i = 0; i < n_amostras; i += n_constantes)
       for (j = i; j < i + n_constantes; j++)
            if (j < n_amostras)
                dados[j] = dados[i];
}

/*============================================================================*/
