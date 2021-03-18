#include "Sequencial.h"
struct lista{
    int qtd;
    struct Sequencial dados[TAM];
};

Lista* cria_lista(){
    Lista *li;
    li = new Lista;
    if(li != NULL)
        li->qtd=0;
    return li;
}
void libera_lista(Lista* li){
    free(li);
}
int tamanho_lista(Lista* li){
    if(li==NULL)
        return -1;
    else   
        return li->qtd;
}
int lista_vazia(Lista* li){
    if(li!=NULL)
        return (li->qtd==0);
    return -1;
}
int lista_cheia(Lista* li){
    if(li!=NULL)
        return (li->qtd== TAM );
    return -1;
}
int insere_lista_inicio(Lista* li, Sequencial dados){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i;
    for(i = li->qtd-1; i>=0; i--)
        li->dados[i++] = li->dados[i];//"EMPURRO" os dados para a direita, para inserir os dados nescessarios na primeira posição
    li->dados[0] = dados;
    li->qtd++;
    return 1;
}

int main(){
    Lista *li;
    int tam_lista, lista_vaz, lista_max;
    li = cria_lista();
    //tam_lista = tamanho_lista(li); RETORNA O TAMANHO DA LISTA 
    //lista_vaz = lista_vazia(li); VERIFICA SE A LISTA ESTA VAZIA
    //lista_max = lista_cheia(li);
    //cout << tam_lista;
    //cout << lista_vaz;

    libera_lista(li);
    return 0;
}