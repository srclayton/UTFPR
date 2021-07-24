#include "pilha.h"
#define MAX_SIZE 10

void initializePlayers(Pilha* p1, Pilha* p2);
void printp(Pilha* p1, Pilha* p2);
int main () {
  Pilha *j1, *j2;
  j1 = create_stack(5);
  j2 = create_stack(5);
  initializePlayers(j1, j2);
  pop(j1);
  pop(j1);
  pop(j1);
  pop(j1);
  printp(j1, j2);
   return 0;
}

void initializePlayers(Pilha* p1, Pilha* p2){
  srand(time(NULL));   // Initialization, should only be called once.
  for(int i=0; i<5;i++)
    push(p1, rand()%10);
  for(int i=0; i<5;i++)
    push(p2, rand()%10);
}
void printp(Pilha* p1, Pilha* p2){
  int tam;
  if(p1->tam > p2->tam)
    tam = p2->tam;
  else
    tam = p1->tam;

  for(int i=0; i< tam; i++) {
    printf("|%d|    |%d|  \n", p1->vetor[i], p2->vetor[i]);
  }
}
