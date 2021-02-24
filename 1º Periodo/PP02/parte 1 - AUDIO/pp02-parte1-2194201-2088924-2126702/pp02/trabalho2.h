/*============================================================================*/
/* IF61C - 2013-1 - TRABALHO 2                                                */
/*----------------------------------------------------------------------------*/
/* Author: Bogdan T. Nassu - nassu@dainf.ct.utfpr.edu.br                      */
/*                                                                            */
/* 2013/07/26                                                                 */
/*============================================================================*/
/** Referencia para as funcoes pedidas para o 2o trabalho das turmas da
 * disciplina IF61C (Fundamentos de Programacao 1), prof. Bogdan T. Nassu,
 * Universidade Tecnologica Federal do Parana. */
/*============================================================================*/

#ifndef __TRABALHO2_REF_H
#define __TRABALHO2_REF_H

/*============================================================================*/

#include "wavfile.h"

/*============================================================================*/
void mudaGanho (double* dados, unsigned long n_amostras, double ganho);
void ruidoPeriodico (double* dados, unsigned long n_amostras, unsigned short intervalo);
void removeRuido (double* dados, unsigned long n_amostras);
void simulaSubAmostragem (double* dados, unsigned long n_amostras, unsigned short n_constantes);

/*----------------------------------------------------------------------------*/
WavHeader generateRandomSignal (unsigned long* n_samples, unsigned short num_channels, unsigned long sample_rate, double** data_l, double** data_r);
WavHeader generateSinusoidSignal (unsigned long* n_samples, unsigned short num_channels, unsigned long sample_rate, double freq, double phase_l, double phase_r, double** data_l, double** data_r);
WavHeader generateSquareSignal (unsigned long* n_samples, unsigned short num_channels, unsigned long sample_rate, double freq, double** data_l, double** data_r);

/*============================================================================*/
#endif /* __TRABALHO2_REF_H */
