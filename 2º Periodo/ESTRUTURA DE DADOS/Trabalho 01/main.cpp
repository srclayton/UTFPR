#include <iostream>
#include "Lista.h"

void menu(){
    cout << "\n================================================";
    cout << "\n|       Digite o numero da opção desejada      |";
    cout << "\n|1- Inserir um dado no inicio da lista;        |";
    cout << "\n|2- Inserir um dado no final da lista;         |";
    cout << "\n|3- Inserir um dado na 'N' posição da lista;   |";
    cout << "\n|4- Retirar um dado no inicio da lista;        |";
    cout << "\n|5- Retirar um dado no final da lista;         |";
    cout << "\n|7- Retirar um dado na 'N' posição da lista;   |";
    cout << "\n|8- Procurar um dado com o RG                  |";
    cout << "\n|9- Mostrar todos os dados;                    |";
    cout << "\n|10- Salvar a lista em um arquivo;             |";
    cout << "\n|11- Ler uma lista de dados;                   |";
    cout << "\n|0- Retirar um dado no inicio da lista;        |";
    cout << "\n================================================\n";
}
void limpaBufferDoTeclado(){
    //__fpurge(stdin);
    fflush(stdin);
}
void printa(Lista* li){
    for (int i = 0; i < li->qtd-1; i++)
        cout << "Nome: " << li->dados[i].nome; //<< " RG: " << li->dados[i].rg;
}
void executar(int escolha){
    Lista *li;
    Pessoa input;
    li = cria_lista();
    if(escolha==1){
        system("clear");
        limpaBufferDoTeclado();
        cout << "\nDigite o nome desejado:";
        cin >> input.nome;
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> input.rg;
        insere_lista_inicio(li,input);
    }else if(escolha ==2){

    }else if(escolha ==3){
        
    }else if(escolha ==4){
        
    }else if(escolha ==5){
        
    }else if(escolha ==6){
        
    }else if(escolha ==7){
        
    }else if(escolha ==8){
        
    }else if(escolha ==9){
        printa(li);
    }else if(escolha ==10){
        
    }else if(escolha ==11){
        
    }else if(escolha ==0){
        
    }else{

    }

    for (int i = 0; i < li->qtd-1; i++)
    {
        cout << "NOME:" << li->dados[i].nome;
    }
    
}

int main(){
    int escolha=1;
    while (escolha !=0)
    {
        menu();
        limpaBufferDoTeclado();
        cin >> escolha;
        executar(escolha);
    }
    
}