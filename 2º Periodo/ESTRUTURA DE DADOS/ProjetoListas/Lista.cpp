#include "Lista.h"
using namespace std;
struct lista{
    int qntd;
    Pessoa dados[TAM];
};

Lista* cria_lista(){
    Lista *li;
    li = new Lista;
    if(li != NULL)
        li->qntd=0;
    return li;
}
void apaga_lista(Lista* li){
    free(li);
}
bool adiciona_lista_inicio(Lista* li, Pessoa dado){
    int i;
    if(li == NULL)
        return 0; // Lista nula
    if(li->qntd == TAM)
        return 0; // Lista cheia, logo não posso adicionar um novo dado;
    for (i = li->qntd-1; i >= 0; i--){
        li->dados[i+1]=li->dados[i]; // empurro os dados para a direita: dado[11] recebe dado[10], dado[10] recebe dado[9]...;
    }
    li->dados[0]=dado;//apos empurrar todos os dados para a direita, o meu dado[0] recebe o input;
    li->qntd++;// encremento a quantidade de Pessoas na minha lista;
    return 1; // Retorno true;
}
bool adiciona_lista_final(Lista* li, Pessoa dado){
    if(li==NULL)
        return 0; // return false;
    if(li->qntd==TAM)
        return 0; // caso quantidade retorne true, minha lista esta cheia, logo retorno um false e saio da função;
    li->dados[li->qntd] = dado; // utilizo a quantidade de Pessoas para alocar o ultimo dado;
    li->qntd++;
    return 1;
}
bool printaLista(Lista* li){
    if(li==NULL)
        return 0;
    for (int i = 0; i < li->qntd; i++)
        cout << li->dados[i].nome << ", "<< li->dados[i].rg <<"\n";   
    return 1; 
}
bool adiciona_lista_n_posicao(Lista* li, Pessoa dado, int posicao){
    if(li==NULL)
        return 0;
    if(li->qntd==TAM)
        return 0;
    if(posicao >= li->qntd)
        return 0;
    /*if(posicao <= li->qntd/2){//Caso a posição desejada seja menor que a metade do tamanho total, empurro os dados para a esquerda, caso contrario empurros para a direita;
        for(int i)
    }else{*/
    int i;
    for (i = li->qntd-1; i-1 >= posicao; i--)
        li->dados[i+1] = li->dados[i]; // empurro os dados da posição N em diante para a direita;
    li->dados[i]=dado;
    li->qntd++;    
    return 1;
}
bool remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qntd==0)
        return 0;
    for(int i =0;i<li->qntd-1;i++)
        li->dados[i] = li->dados[i+1];
    li->qntd--;
    return 1;
}
bool remove_lista_final(Lista* li){
    if(li==NULL)
        return 0;
    if(li->qntd==0)
        return 0;
    //li->dados[li->qntd] = NULL;
    li->qntd--; //APENAS DIMINUO A QNTD, POIS CASO HAJA A NESCESSIDADE DE UMA NOVA ADIÇÃO O VALOR EM QUESTÃO SERA SOBRESCREVIDO;
    return 1;
}
bool remove_lista_n_posicao(Lista* li, int posicao){
    if(li==NULL)
        return 0;
    if(li->qntd==0)
        return 0;
    for(int i = posicao-1; i < li->qntd-1; i++)
        li->dados[i] = li->dados[i+1];
    li->qntd--;
    return 1;
}
bool procura_rg(Lista* li, int inputRg){
    if(li==NULL)
        return 0;
    for(int i = 0, k = li->qntd-1;i<li->qntd; i++, k--){//percorro minha lista de 0 à 10 e de 10 à 0, simultaneamente, comparando o dado de entrada com o dado da minha lista;
        if(li->dados[i].rg == inputRg){
            cout << li->dados[i].rg << li->dados[i].nome;
            return 1;
        } // caso o dado de entrada seja igual o dado da lista, printo os dados;
        if(li->dados[k].rg == inputRg){
            cout << li->dados[k].rg << li->dados[k].nome;
            return 1;
        } // caso o dado de entrada seja igual o dado da lista, printo os dados;
    }
    return 0;
}
void escreve_arquivo(Lista* li){
    ofstream myfile("ListaEscrita.txt");
    if(myfile.is_open()){
        for(int i=0; i< li->qntd;i++)
            myfile << li->dados[i].nome << "," << li->dados[i].rg << "\n";
        cout << "Lista salva com sucesso!";   
    }else
        cout << "Não foi possivel abrir o arquivo!";
}
void abrir_e_ler_arquivo(Lista* li){
    string linha, inputNome, rgString;
    int inputRg, tamLinha,localizaEspaco=0,i=0;
    ifstream myfile("NomeRG10.txt");
    if(myfile.is_open()){
        while (getline(myfile,linha))
        {
            localizaEspaco = linha.find(","); // localiza a primeira virgula;
            tamLinha= linha.size(); // recebo o tamanho da minha linha;
            inputNome=linha.substr(0,localizaEspaco); // retorno a string da posição 0 até a virgula;
            rgString = linha.substr(localizaEspaco+1,tamLinha); // recebo o RG em string obs : +2 para retirar a ',' e o 'espaço';
            inputRg = stoi(rgString);
            li->dados[i].nome= inputNome;
            li->dados[i].rg= inputRg;
            li->qntd++;
            i++;
        }
        cout << "Lista aberta com sucesso!";    

    }else
        cout << "Não foi possivel abrir o arquivo!";
}
void limpaBufferDoTeclado(){
    //__fpurge(stdin);
    fflush(stdin);
}
void menu(){
    cout << "\n================================================";
    cout << "\n|       Digite o numero da opção desejada      |";
    cout << "\n|1- Inserir um dado no inicio da lista;        |";
    cout << "\n|2- Inserir um dado no final da lista;         |";
    cout << "\n|3- Inserir um dado na 'N' posição da lista;   |";
    cout << "\n|4- Retirar um dado no inicio da lista;        |";
    cout << "\n|5- Retirar um dado no final da lista;         |";
    cout << "\n|6- Retirar um dado na 'N' posição da lista;   |";
    cout << "\n|7- Procurar um dado com o RG                  |";
    cout << "\n|8- Mostrar todos os dados;                    |";
    cout << "\n|9- Salvar a lista em um arquivo;             |";
    cout << "\n|10- Ler uma lista de dados;                   |";
    cout << "\n|0- Para sair do programa;                     |";
    cout << "\n================================================\n";
}
void executar(int escolha, Lista* li){
    Pessoa inputDado;
    bool retorno;
    int posicao, inputRg,rgRetornado;
    if(escolha==1){ // INSERE UM DADO NO INICIO DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o nome desejado:";
        cin >> inputDado.nome;
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputDado.rg;
        retorno = adiciona_lista_inicio(li, inputDado);
        if(!retorno){
            cout << "ATENÇÃO      ";
            cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
        }else{
            cout << "ATENÇÃO      ";
            cout << "Dado adicionado com sucesso!."; 
        }
        system("clear");
    }else if(escolha ==2){ // INSERE UM DADO NO FINAL DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o nome desejado:";
        cin >> inputDado.nome;
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputDado.rg;
        retorno = adiciona_lista_final(li, inputDado);
        if(!retorno){
            cout << "ATENÇÃO      ";
            cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
        }else{
            cout << "ATENÇÃO      ";
            cout << "Dado adicionado com sucesso!."; 
        }              
        system("clear");        
    }else if(escolha ==3){ // INSERE UM DADO NA N POSIÇÃO DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o nome desejado:";
        cin >> inputDado.nome;
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputDado.rg;
        limpaBufferDoTeclado();
        cout << "\nDigite a posição:";
        cin >> posicao;
        retorno = adiciona_lista_n_posicao(li, inputDado, posicao);
        if(!retorno){
            cout << "ATENÇÃO      ";
            cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
        }else{
            cout << "ATENÇÃO      ";
            cout << "Dado adicionado com sucesso!."; 
        }  
        system("clear");
    }else if(escolha ==4){ // REMOVE UM DADO NO INICIO DA LISTA
        retorno = remove_lista_inicio(li);
        if(!retorno)
            cout << "Não foi possivel remover.";
        else
            cout << "Dado retirado com sucesso!";
        system("clear");
    }else if(escolha ==5){ // REMOVE UM DADO NO FINAL DA LISTA
        retorno = remove_lista_final(li);
        if(!retorno)
            cout << "Não foi possivel remover.";
        else    
            cout << "Dado retirado com sucesso!";
        system("clear");
    }else if(escolha ==6){ // REMOVE UM DADO NA N POSIÇÃO DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite a posição:";
        cin >> posicao;
        retorno = remove_lista_n_posicao(li, posicao);
        if(!retorno)
            cout << "Não foi possivel remover.";
        else
            cout << "Dado retirado com sucesso!";
        system("clear");
    }else if(escolha ==7){ // FAZ A BUSCA DE UM RG NA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputRg;
        retorno = procura_rg(li, inputRg);
        if(!retorno)
            cout << "Não foi possivel encontrar este RG.";
        system("clear");
    }else if(escolha ==8){
        printaLista(li);
        sleep(3);
        system("clear");
    }else if(escolha ==9){
        escreve_arquivo(li);
        system("clear");
    }else if(escolha ==10){
        abrir_e_ler_arquivo(li);
        system("clear");
    }
    /*Pessoa aux;
    aux = li->dados[0];

    cout << aux.nome;*/
    
}