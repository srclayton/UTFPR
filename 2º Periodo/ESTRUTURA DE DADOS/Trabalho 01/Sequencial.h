#include <iostream>
#include <new>
#include <fstream>
#include <string>
#define TAM 10
using namespace std;

struct Sequencial
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
int insere_lista_inicio(Lista* li, Sequencial dados);