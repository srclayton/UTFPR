#include "Sequencial.h"
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
//Falta decidir se a fila vai ser empurrada para a direita ou esquerda;
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
    //Lista *li;
    int /*tam_lista, lista_vaz, lista_max,*/escolha=1;
    //li = cria_lista();
    while (escolha != 0){    
        menu();
        limpaBufferDoTeclado();
        cin >> escolha;
        executar(escolha);
    }

        
    //tam_lista = tamanho_lista(li); RETORNA O TAMANHO DA LISTA 
    //lista_vaz = lista_vazia(li); VERIFICA SE A LISTA ESTA VAZIA
    //lista_max = lista_cheia(li);
    //cout << tam_lista;
    //cout << lista_vaz;

    //libera_lista(li);
    return 0;
}