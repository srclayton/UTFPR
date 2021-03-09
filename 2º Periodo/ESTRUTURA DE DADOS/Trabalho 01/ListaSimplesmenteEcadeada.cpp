#include <iostream>
#include <new>
#include <fstream>
#include <string>
using namespace std;

typedef struct Lista{
    string linha;
    struct Lista *prox;
    struct Lista *prim;
}lista;

void newCell(lista **topo, string linha){
    lista *novo;
    novo = new lista;
    novo->linha = linha;
    if(*topo == NULL){
        novo->prox= NULL;
        *topo = novo;
        //novo->prox = *topo;
        //*topo = novo;
    }
    else{
        //novo->prox= NULL;
        //*topo = novo;
        novo->prox = *topo;
        *topo = novo;
        topo->prox = novo;
    }
    
}
void print(lista *topo){
    lista *aux;
    aux = topo;
    int aux2 =0;
    int i=0;
    while(aux != NULL){
        cout << aux->linha;
        i++;
        if(aux->prox != NULL){
            cout <<" \n | I =" << i; //cout <<" passei aqui ";
            
        }           
        else
            cout << "\nFIM!";
        aux = aux->prox;
        
    }
    cout << "\nI =: " << i;
}
int main(){
    lista *topo = NULL;
    string line;
    ifstream myfile ("NomeRG10.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
        newCell(&topo, line);
        //cout << "\n" << topo->linha ;
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
    print(topo);

    return 0;
}