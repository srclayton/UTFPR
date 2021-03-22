#include <string>
#include <new>
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define NOME_ARQUIVO "src/NomeRG1M.txt"
using namespace std;

struct pessoa_enc{
    string nome;
    int rg;
};

typedef struct lista_enc* Lista;
typedef struct pessoa_enc PessoaEnc;
Lista* cria_lista_encad();
void apaga_lista_encad(Lista* li);
bool adiciona_lista_enc_inicio(Lista* li, PessoaEnc dado, int* nCompa, int* nCopi);
bool adiciona_lista_enc_final(Lista* li, PessoaEnc dado, int* nCompa, int* nCopi);
bool adiciona_lista_enc_n_posicao(Lista* li, PessoaEnc dado, int posicao, int* nCompa, int* nCopi);
bool remove_lista_enc_inicio(Lista* li, int* nCompa, int* nCopi);
bool remove_lista_enc_final(Lista* li, int* nCompa, int* nCopi);
bool remove_lista_enc_n_posicao(Lista* li, int posicao, int* nCompa, int* nCopi);
bool procura_rg_enc(Lista* li, int inputRg, int* nCompa, int* nCopi);
int tamanho_lista(Lista* li, int* nCompa, int* nCopi);
bool imprime_lista(Lista* li, int* nCompa, int* nCopi);
void escreve_arquivo_enc(Lista* li, int* nCompa, int* nCopi);
void abrir_e_ler_arquivo_enc(Lista*li , int* nCompa, int* nCopi);
void limpaBufferListaEnc();
void menu();