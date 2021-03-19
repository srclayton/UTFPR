#include <string>
#include <new>
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#define TAM 10
using namespace std;

struct pessoa{
    string nome;
    int rg;
};
typedef struct lista Lista;
typedef pessoa Pessoa;

Lista* cria_lista();
bool adiciona_lista_inicio(Lista* li, Pessoa dado);
bool adiciona_lista_final(Lista* li, Pessoa dado);
bool adiciona_lista_n_posicao(Lista* l1, Pessoa dado, int posicao);
bool printaLista(Lista* li);
bool remove_lista_inicio(Lista* li);
bool remove_lista_final(Lista* li);
bool remove_lista_n_posicao(Lista* li, int posicao);
bool procura_rg(Lista* li, int inputRg);
void escreve_arquivo(Lista* li);
void abrir_e_ler_arquivo(Lista* li);
void limpaBufferDoTeclado();
void menu();
void executar(int escolha, Lista* li);