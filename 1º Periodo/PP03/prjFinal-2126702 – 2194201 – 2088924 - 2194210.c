/*============================================================================*/
/* Autores: Clayton da Silva da Rocha      - RA: 2194201                      */
/*          Lucas Gomes Santana            - RA: 2126702                      */
/*          Mateus de Matos Leal           - RA: 2089924                      */
/*          Fernando Antonio Taborda Neto  - RA: 2194210                      */
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho3.h"
#include "imagem.h"
#include "gerador_de_testes.h"

#define LIMIAR 30
#define BORDAS 25

double calculaDistancia (Imagem* bg, Imagem* img1, Imagem* img2)
{
    Imagem *img_saida1, *img_saida2;
    coord *img_s1, *img_s2;
    long double resultado;

    img_s1 = malloc (sizeof(img_s1));
    img_s2 = malloc (sizeof(img_s2));

    //Cria as imagens de saida com apenas 1 canal.
    img_saida1 = criaImagem(img1->largura, img1->altura, 1);
    img_saida2 = criaImagem(img2->largura, img2->altura, 1);

    //Passa a imagem RGB com para imagem com 1 canal.
    converteBrancoPreto(img_saida1, img1);
    converteBrancoPreto(img_saida2, img2);

    //Preserva somente o carro nas imagens saida.
    removeBackground(img1, bg, img_saida1);
    removeBackground(img2, bg, img_saida2);

    //Passa um filtro para tirar os ruidos mais "grossos".
    mascaraMedia(img_saida1);
    mascaraMedia(img_saida2);

    //Passa filtro para tirar ruidos mais "finos".
    img_saida1 = removeRuido(img_saida1);
    img_saida2 = removeRuido(img_saida2);

    //Detecta a posição do carro.
    detectaObjeto(img_saida1, img_s1);
    detectaObjeto(img_saida2, img_s2);

    resultado = pitagorasDistancia(img_s1, img_s2);
    return resultado;

}

/** Conta a quantidade de vizinhos para um pixel especifico.
 *
 * Parâmetros: int i: corresponde a linha da matriz.
 *             int j: corresponde a coluna da matriz.
 *             Imagem *img: imagem a ser processada.
 *
 * Valor de retorno: a quantidade de vizinhos. */

int contaVizinhos (int i, int j, Imagem *img)
{
    int qntVizinhos = 0;

    qntVizinhos = img->dados[0][i][j-1] + img->dados[0][i-1][j-1]
                + img->dados[0][i-1][j] + img->dados[0][i-1][j+1]
                + img->dados[0][i][j+1] + img->dados[0][i+1][j-1]
                + img->dados[0][i+1][j] + img->dados[0][i+1][j+1];

    return qntVizinhos;
}

/** Transforma uma imagem RGB em monocromática.
 *
 * Parâmetros: Imagem *img_saida: Imagem monocromática de saida.
 *             Imagem *img1: Imagem RGB de entrada.
 *
 * Valor de retorno: nenhum. */

void converteBrancoPreto(Imagem *img_saida, Imagem *img1)
{
    int i, j, k, escala_cinza;

    for(i = 0; i < img1->altura - BORDAS; i++)
    {
        for(j = 0; j < img1->largura - BORDAS; j++)
        {
            escala_cinza = 0;

            for(k = 0; k < 3; k++)
            {
                escala_cinza += img1->dados[k][i][j];
            }

            img_saida->dados[0][i][j] = escala_cinza / 3;
        }
    }
}

/** Remove o fundo da imagem deixando apenas o veiculo e alguns ruídos.
 *
 * Parâmetros: Imagem *img: imagem de entrada.
 *             Imagem *bg: fundo da imagem.
 *             Imagem *imgSaida: imagem apenas com o veiculo e alguns ruídos.
 *
 * Valor de retorno: nenhum. */

void removeBackground(Imagem* img, Imagem* bg, Imagem* imgSaida)
{
    int i, j;

    for(i = 0; i < img->altura; i++)
    {
        for(j = 0; j < img->largura; j++)
        {
            if(abs(img->dados[0][i][j] - bg->dados[0][i][j]) < LIMIAR)
                imgSaida->dados[0][i][j] = 0;

            else
                imgSaida->dados[0][i][j] = 255;
        }
    }
}

/** Remove pixeis brancos que não possuem mais que 4 vizinhos (ruídos).
 *
 * Parâmetros: Imagem *img: imagem de entrada.
 *
 * Valor de retorno: imagem sem ruidos. */

Imagem* removeRuido(Imagem *img)
{
    int i, j, vizinhos;
    Imagem *img_saida = criaImagem(img->largura, img->altura, 1);

    for(i = 1; i < img_saida->altura - 1; i++)
    {

        for(j = 1; j < img->largura - 1; j++)
        {
            vizinhos = contaVizinhos(i, j, img);

            if(vizinhos <= 4*255)
                img_saida->dados[0][i][j] = 0;
            else
                img_saida->dados[0][i][j] = 255;
        }
    }
    return (img_saida);
}

/** Calcula a média entre 8 vizinhos de um pixel para reduzir os ruídos.
 *
 * Parâmetros: Imagem *img: imagem de entrada.
 *
 * Valor de retorno: nenhum. */

void mascaraMedia(Imagem *img)
{
    int i, j, mediaVizinhos;

    for(i = 1; i < img->altura - 1; i++)
    {
        for(j = 1; j < img->largura - 1; j++)
        {
            mediaVizinhos = contaVizinhos(i, j, img) / 8;
            img->dados[0][i][j] = mediaVizinhos;
        }
    }
}

/** Detecta dois pontos diferentes do veículo e calcula o ponto centróide.
 *
 * Parâmetros: Imagem *img_saida: imagem do veículo.
 *             coordXY *img: coordenadas (X,Y) do ponto centróide do veículo.
 *
 * Valor de retorno: nenhum. */

void detectaObjeto(Imagem *img_saida, coord* img)
{
    int somaX = 0;
    int somaY = 0;
    int i, j;

    for (i = BORDAS; i < img_saida->altura - BORDAS; i++)
    {
        for (j = BORDAS; j < img_saida->largura - BORDAS; j++)
            if (img_saida->dados[0][i][j] == 255)
            {
                somaX += i;
                somaY += j;
                i = img_saida->altura - BORDAS;
                j = img_saida->largura - BORDAS;
            }
    }

    for (i = img_saida->altura - BORDAS; i > BORDAS; i--)
    {
        for (j = img_saida->largura - BORDAS; j > BORDAS; j--)
        {
            if (img_saida->dados[0][i][j] == 255)
            {
                somaX += i;
                somaY += j;
                i = 0;
                j = 0;
            }
        }
    }

    img->x = somaX / 2;
    img->y = somaY / 2;
}

/** Aplica a fórmula de Pitagoras para estimar a distância percorrida pelo carro.
 *
 * Parâmetros: coord *img1: coordenadas do veículo na primeira imagem.
 *             coord *img2: coordenadas do veículo na segunda imagem.
 *
 * Valor de retorno: aproximação da distância percorrida pelo carro calculada em píxels. */

double pitagorasDistancia(coord* img1, coord* img2)
{
    long double aux1, aux2;
    double resultado;


    aux1 = abs(img2->x - img1->x);
    aux2 = abs(img2->y - img1->y);

    aux1 = pow(aux1, 2);
    aux2 = pow(aux2, 2);

    resultado = sqrt(aux1+aux2);

    return resultado;
}
