#include <string>
#include <new>
#include <iostream>
#include <fstream>
#define TAM 10
using namespace std;

struct Pessoa
{
    string nome;
    int rg;
};
typedef struct lista Lista;
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
bool insere_lista_inicio(Lista* li, Pessoa dados);
int insere_lista_final(Lista* li, Pessoa dados);
int insere_lista_n_posicao(Lista* li, Pessoa dados, int posicao);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lita_n_posicao(Lista* li, int posicao);
void menu();
void executar(int escolha);
void limpaBufferDoTeclado();
void printa(Lista* li);