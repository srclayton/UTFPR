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
bool adiciona_lista_enc_inicio(Lista* li, PessoaEnc dado, long int* nCompa, long int* nCopi, int* qntd);
bool adiciona_lista_enc_final(Lista* li, PessoaEnc dado, long int* nCompa, long int* nCopi, int* qntd);
bool adiciona_lista_enc_n_posicao(Lista* li, PessoaEnc dado, int posicao, long int* nCompa, long int* nCopi, int* qntd);
bool remove_lista_enc_inicio(Lista* li, long int* nCompa, long int* nCopi, int* qntd);
bool remove_lista_enc_final(Lista* li, long int* nCompa, long int* nCopi, int* qntd);
bool remove_lista_enc_n_posicao(Lista* li, int posicao, long int* nCompa, long int* nCopi, int* qntd);
bool procura_rg_enc(Lista* li, int inputRg, long int* nCompa, long int* nCopi);
int tamanho_lista(Lista* li, long int* nCompa, long int* nCopi);
bool imprime_lista(Lista* li, long int* nCompa, long int* nCopi);
void escreve_arquivo_enc(Lista* li, long int* nCompa, long int* nCopi);
void abrir_e_ler_arquivo_enc(Lista*li , long int* nCompa, long int* nCopi, int* qntd);
bool adiciona_lista_arquivo(Lista* li, PessoaEnc dado, long int* nCompa, long int* nCopi);
void limpaBufferListaEnc();
void menu();