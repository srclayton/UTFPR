#include "Lista.h"
struct lista{
    int qtd;
    struct Pessoa dados[TAM];
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
        return 0;
    else   
        return li->qtd;
}
int lista_vazia(Lista* li){
    if(li!=NULL)
        return (li->qtd==0);
    return 0;
}
int lista_cheia(Lista* li){
    if(li!=NULL)
        return (li->qtd== TAM);
    return 0;
}
bool insere_lista_inicio(Lista* li, Pessoa dados){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i;
    for(i = li->qtd-1; i>=0; i--)
        li->dados[i++] = li->dados[i];//"EMPURRO" os dados para a direita, para inserir os dados nescessarios na primeira posição
    li->dados[0] = dados;//ja com os dados todos "empurrados para direita", aloco os dados na posição [0]
    li->qtd++;
    return 1;
}
int insere_lista_final(Lista* li, Pessoa dados){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = dados;
    li->qtd++;
    return 1;
}
int insere_lista_n_posicao(Lista* li, Pessoa dados, int posicao){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i;
    for (i = li->qtd-1; i >= posicao; i--) //"EMPURRO" OS DADOS DA POSIÇÃO TAM-1 ATÉ "N" PARA A DIREITA
        li->dados[i++] = li->dados[i];
    li->dados[posicao] = dados;
    li->qtd++;
    return 1;
}
int remove_lista_inicio(Lista* li){
    if(li==NULL)
        return 0;
    if(li->qtd=0)
        return 0;
    for(int i = 0; i < li->qtd-1; i++)
        li->dados[0] = li->dados[i++]; //PEGO TODOS OS DADOS A DIREITA E RETORNO UM ELEMENTO;
    li->qtd--;
    return 1;
}
int remove_lista_final(Lista* li){
    if(li==NULL)
        return 0;
    if(li->qtd==0)
        return 0;
    //li->dados[li->qtd-1] = NULL;
    li->qtd--; // APENAS DIMINUO A QNT DA LISTA, POIS CASO HAJA A NESCESSIDADE DE UMA NOVO DADO, O MESMO IRA SOBRE ESCREVELO.
    return 1;
}
int remove_lista_n_posicao(Lista* li, int posicao){
    if(li==NULL)
        return 0;
    if(li->qtd==0)
        return 0;
    for(int i = posicao; i < li->qtd-1; i++)
        li->dados[i] = li->dados[i++];
    li->qtd--;
    return 1;    
}