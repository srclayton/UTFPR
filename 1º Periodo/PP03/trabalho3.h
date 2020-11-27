/*============================================================================*/
/* MÓDULO QUE REALIZA O CÁLCULO DA DISTANCIA                                  */
/*----------------------------------------------------------------------------*/
/* Autor: Bogdan T. Nassu - nassu@dainf.ct.utfpr.edu.br                       */
/*============================================================================*/

#ifndef __TRABALHO3_H
#define __TRABALHO3_H

/*============================================================================*/

#include "imagem.h"

/*============================================================================*/
/* Função central do trabalho. */

typedef struct
{
    int x;
    int y;
} coord;

void detectaObjeto (Imagem* img_saida, coord *img);
double pitagorasDistancia (coord* img1, coord* img2);
Imagem* removeRuido (Imagem *img);

double calculaDistancia (Imagem* bg, Imagem* img1, Imagem* img2);
void mascaraMedia (Imagem *img);
void converteBrancoPreto (Imagem *img_saida1, Imagem *img1);
void removeBackground (Imagem* img, Imagem* bg, Imagem* imgSaida);


/*============================================================================*/
#endif /* __TRABALHO3_H */
