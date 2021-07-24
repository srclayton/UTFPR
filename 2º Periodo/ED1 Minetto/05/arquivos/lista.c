#include "lista.h"

int conta_nos_itr (Lista* lista) {
    if(lista == NULL)
      return 0;
    if(lista->next == NULL)
      return 1;
    Lista* tmp= lista;
    int i=0;
    while (tmp != NULL) {
      i++;
      tmp = tmp->next;
    }
    return i; 
}

int conta_nos_rec (Lista* lista) {
    if(lista == NULL)
      return 0;
    if(lista->next == NULL)
      return 1;
    else{
     return 1 + conta_nos_rec(lista->next);
   }
}

int procura_itr (Lista* lista, int elemento) {
    if(lista == NULL)
      return -1;

    Lista* tmp = lista;
    int i=0;
    while (tmp != NULL) {
      if(tmp->info == elemento)
        return i;
      tmp = tmp->next;
      i++;
    }
    return -1;
}

int procura_rec (Lista* lista, int elemento) {
    if(lista == NULL)
      return -1;

    if(lista->info == elemento)
      return 0;
    else
      return 1 + procura_rec(lista->next, elemento);

}

int lista_max_itr (Lista* lista) {
    if(lista == NULL)
      return 0;
    if(lista->next == NULL)
      return lista->info;

    Lista* tmp = lista;
    int maior = 0;
    while (tmp != NULL) {
      if(maior <= tmp->info)
        maior = tmp->info;
      tmp = tmp->next;
    }
    return maior;
}

/*Você pode usar outras funções aqui se achar necessário!*/
int lista_max_rec (Lista* lista) {
   /*TERMINAR*/
    if(lista == NULL)
      return 0;
    if(lista->next == NULL)
      return lista->info;
    if(lista->info <= lista_max_rec(lista->next))
      lista_max_rec(lista->next);
    else
      return lista->info;
}

int lista_soma_itr (Lista* lista) {
   /*TERMINAR*/
    if(lista == NULL)
      return 0;
    if(lista->next == NULL)
      return lista->info;

    Lista* tmp = lista;
    int soma = 0;
    while(tmp!= NULL){
      soma += tmp->info;
      tmp = tmp->next;
    }
    return soma;
}

int lista_soma_rec (Lista* lista) {
   /*TERMINAR*/
   if(lista == NULL)
     return 0;
   if(lista->next == NULL)
     return lista->info;
   else{
    return lista->info + lista_soma_rec(lista->next);
  }
}

/*Você pode usar outras funções aqui se achar necessário!*/
void imprimir_invertida_itr (Lista* lista) {
   /*TERMINAR*/
    Lista* tmp;
    Lista* aux = criar_lista();
    for(tmp = lista; tmp != NULL;tmp =  tmp->next)
      aux = inserir(aux, tmp->info);
    imprimir_lista(aux);
}

void imprimir_invertida_rec (Lista* lista) {
   /*TERMINAR*/
    if(lista!=NULL){
      imprimir_invertida_rec(lista->next);
      printf("%d ", lista->info);
    }
}

/*Função para criar uma lista encadeada vazia!*/
Lista* criar_lista (void) {
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista* inserir (Lista *lista, int elem) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista (Lista *lista) {
   Lista *v; /*var. para percorrer a lista*/
   for (v = lista; v != NULL; v = v->next) {
      printf("%d ", v->info);
   }
   printf("\n");
}

/*Função para desalocar uma lista encadeda!*/
void destruir_lista (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}
