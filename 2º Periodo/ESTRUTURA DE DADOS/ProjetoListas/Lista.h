#include <string>
#include <new>
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define TAM 1000000
#define NOME_ARQUIVO "src/NomeRG1M.txt"
using namespace std;

struct pessoa{
    string nome;
    int rg;
};
typedef struct lista Lista_Seq;
typedef pessoa Pessoa;

Lista_Seq* cria_lista();
void apaga_lista(Lista_Seq* li);
bool adiciona_lista_inicio(Lista_Seq* li, Pessoa dado);
bool adiciona_lista_final(Lista_Seq* li, Pessoa dado);
bool adiciona_lista_n_posicao(Lista_Seq* l1, Pessoa dado, int posicao);
bool printaLista(Lista_Seq* li);
bool remove_lista_inicio(Lista_Seq* li);
bool remove_lista_final(Lista_Seq* li);
bool remove_lista_n_posicao(Lista_Seq* li, int posicao);
bool procura_rg(Lista_Seq* li, int inputRg);
void escreve_arquivo(Lista_Seq* li);
void abrir_e_ler_arquivo(Lista_Seq* li);
void limpaBufferDoTeclado();
void menu();
void executar(int escolha, Lista_Seq* li);