#include <iostream>
#include <new>
using namespace std;

struct node{
    int info;
    struct node *proximo;
};
void novoDado(node  **usuario, int valor){
    node *novo = new node;
    if(novo!=NULL){
        novo->info=valor;
        novo->proximo=NULL;
        if(usuario==NULL){
            *usuario=novo;
        }
    }
}
void printaLista(node *lista){
    node *aux = new node;
    aux= lista;
    while(aux != NULL){
        printf("%d", aux->info);
        if(aux->proximo != NULL)
            printf(" -> ");
        else
            printf("\n");
        aux = aux->proximo;
    }
    printf("\n");
}
int main(){
    node *usuario = new node;
    usuario=NULL;
    novoDado(&usuario, 1);
    novoDado(&usuario, 2);
    novoDado(&usuario, 3);
    printaLista(usuario);
}