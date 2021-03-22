#include "Lista.h"

using namespace std;
struct lista{
    int qntd,numDeCopi,numDeCompa;
    Pessoa dados[TAM];
};

Lista_Seq* cria_lista(){
    Lista_Seq *li;
    li = new Lista_Seq;
    if(li != NULL){
        li->qntd=0;
        li->numDeCompa=0;
        li->numDeCopi=0;
    }
    return li;
}
void apaga_lista(Lista_Seq* li){
    free(li);
}
bool adiciona_lista_inicio(Lista_Seq* li, Pessoa dado){
    int i;
    if(li == NULL)
        return 0; // Lista nula
    li->numDeCompa++;
    if(li->qntd == TAM)
        return 0; // Lista cheia, logo não posso adicionar um novo dado;
    li->numDeCompa++;
    for (i = li->qntd-1; i >= 0; i--){
        li->dados[i+1]=li->dados[i]; // empurro os dados para a direita: dado[11] recebe dado[10], dado[10] recebe dado[9]...;
        li->numDeCopi++;
    }
    li->dados[0]=dado;//apos empurrar todos os dados para a direita, o meu dado[0] recebe o input;
    li->qntd++;// encremento a quantidade de Pessoas na minha lista;
    return 1; // Retorno true;
}
bool adiciona_lista_final(Lista_Seq* li, Pessoa dado){
    if(li==NULL)
        return 0; // return false;
    li->numDeCompa++;
    if(li->qntd==TAM)
        return 0; // caso quantidade retorne true, minha lista esta cheia, logo retorno um false e saio da função;
    li->numDeCompa++;
    li->dados[li->qntd] = dado; // utilizo a quantidade de Pessoas para alocar o ultimo dado;
    li->qntd++;
    return 1;
}
bool printaLista(Lista_Seq* li){
    if(li==NULL)
        return 0;
    li->numDeCompa++;
    for (int i = 0; i < li->qntd; i++)
        cout << i+1 << "° " << li->dados[i].nome << ", "<< li->dados[i].rg <<"\n";   
    return 1; 
}
bool adiciona_lista_n_posicao(Lista_Seq* li, Pessoa dado, int posicao){
    if(li==NULL)
        return 0;
    li->numDeCompa++;
    if(li->qntd==TAM)
        return 0;
    li->numDeCompa++;
    if(posicao >= li->qntd)
        return 0;
    li->numDeCompa++;
    /*if(posicao <= li->qntd/2){//Caso a posição desejada seja menor que a metade do tamanho total, empurro os dados para a esquerda, caso contrario empurros para a direita;
        for(int i)
    }else{*/
    int i;
    for (i = li->qntd-1; i >= posicao; i--){
        li->dados[i+1] = li->dados[i]; // empurro os dados da posição N em diante para a direita;
        li->numDeCopi++;
    }
    
    li->dados[i+1]=dado;
    li->qntd++;    
    return 1;
}
bool remove_lista_inicio(Lista_Seq* li){
    if(li == NULL)
        return 0;
    li->numDeCompa++;
    if(li->qntd==0)
        return 0;
    li->numDeCompa++;
    for(int i =0;i<li->qntd-1;i++){
        li->dados[i] = li->dados[i+1];
        li->numDeCopi++;
    }
    li->qntd--;
    return 1;
}
bool remove_lista_final(Lista_Seq* li){
    if(li==NULL)
        return 0;
    li->numDeCompa++;
    if(li->qntd==0)
        return 0;
    li->numDeCompa++;
    //li->dados[li->qntd] = NULL;
    li->qntd--; //APENAS DIMINUO A QNTD, POIS CASO HAJA A NESCESSIDADE DE UMA NOVA ADIÇÃO O VALOR EM QUESTÃO SERA SOBRESCREVIDO;
    return 1;
}
bool remove_lista_n_posicao(Lista_Seq* li, int posicao){
    if(li==NULL)
        return 0;
    li->numDeCompa++;
    if(li->qntd==0)
        return 0;
    li->numDeCompa++;
    for(int i = posicao-1; i < li->qntd-1; i++){
        li->dados[i] = li->dados[i+1];
        li->numDeCopi++;
    }
    li->qntd--;
    return 1;
}
bool procura_rg(Lista_Seq* li, int inputRg){
    if(li==NULL)
        return 0;
    li->numDeCompa++;
    for(int i = 0, k = li->qntd-1;i<li->qntd; i++, k--){//percorro minha lista de 0 à 10 e de 10 à 0, simultaneamente, comparando o dado de entrada com o dado da minha lista;
        if(li->dados[i].rg == inputRg){
            li->numDeCompa++;
            cout << "NOME:"<< li->dados[i].rg << ", RG:"<< li->dados[i].nome << " Posição:" << i <<"    ";
            return 1;
        } // caso o dado de entrada seja igual o dado da lista, printo os dados;
        if(li->dados[k].rg == inputRg){
            li->numDeCompa++;
            cout << "NOME:"<< li->dados[k].rg << ", RG:"<< li->dados[k].nome << " Posição:" << k <<"    ";
            return 1;
        } // caso o dado de entrada seja igual o dado da lista, printo os dados;
    }
    return 0;
}
void escreve_arquivo(Lista_Seq* li){
    ofstream myfile("src/ListaEscrita.txt");
    if(myfile.is_open()){
        for(int i=0; i< li->qntd;i++)
            myfile << li->dados[i].nome << "," << li->dados[i].rg << "\n";
        cout << "Lista salva com sucesso!";   
    }else
        cout << "Não foi possivel salvar o arquivo!";
}
void abrir_e_ler_arquivo(Lista_Seq* li){
    string linha, inputNome, rgString;
    int inputRg, tamLinha,localizaEspaco=0,i=li->qntd, k=0,aux=0;
    ifstream myfile(NOME_ARQUIVO);
    if(myfile.is_open()){
        while (getline(myfile,linha))
        {   
            if(li->qntd!=TAM){
                li->numDeCompa++;
                localizaEspaco = linha.find(","); // localiza a primeira virgula;
                tamLinha= linha.size(); // recebo o tamanho da minha linha;
                inputNome=linha.substr(0,localizaEspaco); // retorno a string da posição 0 até a virgula;
                rgString = linha.substr(localizaEspaco+1,tamLinha); // recebo o RG em string obs : +2 para retirar a ',' e o 'espaço';
                inputRg = stoi(rgString);
                li->dados[i].nome= inputNome;
                li->dados[i].rg= inputRg;
                li->qntd++;
                i++;
                k++;
                li->numDeCopi++;
            }else{
                cout << "Não foi possivel adicionar os dados " << k << "em diante."; 
                myfile.close();
                aux=1;
            }  
        }
        if(aux!=1)
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
    cout << "\n|             LISTA SEQUENCIAL                 |";
    cout << "\n================================================\n";
}
void executar(int escolha, Lista_Seq* li){
    li->numDeCompa++;
    Pessoa inputDado;
    bool retorno;
    int posicao, inputRg;
    long double tempoDeExecucao;
    clock_t inicioDaFuncao, finalDaFuncao;
    if(escolha==1){ // INSERE UM DADO NO INICIO DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o nome desejado:";
        cin >> inputDado.nome;
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputDado.rg;
        inicioDaFuncao = clock();
        retorno = adiciona_lista_inicio(li, inputDado);
        if(!retorno){
            cout << "ATENÇÃO      ";
            cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
        }else{
            cout << "ATENÇÃO      ";
            cout << "Dado adicionado com sucesso!."; 
        }
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==2){ // INSERE UM DADO NO FINAL DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o nome desejado:";
        cin >> inputDado.nome;
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputDado.rg;
        inicioDaFuncao = clock();
        retorno = adiciona_lista_final(li, inputDado);
        if(!retorno){
            cout << "ATENÇÃO      ";
            cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
        }else{
            cout << "ATENÇÃO      ";
            cout << "Dado adicionado com sucesso!."; 
        }       
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";    
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
        inicioDaFuncao = clock();
        retorno = adiciona_lista_n_posicao(li, inputDado, posicao);
        if(!retorno){
            cout << "ATENÇÃO      ";
            cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
        }else{
            cout << "ATENÇÃO      ";
            cout << "Dado adicionado com sucesso!."; 
        }  
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==4){ // REMOVE UM DADO NO INICIO DA LISTA
        inicioDaFuncao = clock ();
        retorno = remove_lista_inicio(li);
        if(!retorno)
            cout << "Não foi possivel remover.";
        else
            cout << "Dado retirado com sucesso!";
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==5){ // REMOVE UM DADO NO FINAL DA LISTA
        inicioDaFuncao = clock();
        retorno = remove_lista_final(li);
        if(!retorno)
            cout << "Não foi possivel remover.";
        else    
            cout << "Dado retirado com sucesso!";
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==6){ // REMOVE UM DADO NA N POSIÇÃO DA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite a posição:";
        cin >> posicao;
        inicioDaFuncao = clock();
        retorno = remove_lista_n_posicao(li, posicao);
        if(!retorno)
            cout << "Não foi possivel remover.";
        else
            cout << "Dado retirado com sucesso!";
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==7){ // FAZ A BUSCA DE UM RG NA LISTA
        limpaBufferDoTeclado();
        cout << "\nDigite o RG:";
        cin >> inputRg;
        inicioDaFuncao = clock();
        retorno = procura_rg(li, inputRg);
        if(!retorno)
            cout << "Não foi possivel encontrar este RG.";
        finalDaFuncao = clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==8){
        inicioDaFuncao = clock();
        retorno = printaLista(li);
        if(!retorno)
            cout << "Não foi possivel mostrar a lista.";
        finalDaFuncao = clock();
        finalDaFuncao = clock();
        tempoDeExecucao= finalDaFuncao - inicioDaFuncao;
        sleep(4);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==9){
        inicioDaFuncao= clock();
        escreve_arquivo(li);
        finalDaFuncao= clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }else if(escolha ==10){
        inicioDaFuncao = clock();
        abrir_e_ler_arquivo(li);
        finalDaFuncao= clock();
        tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
        cout << "C(n):" << li->numDeCompa << "  |  " << "M(n):" <<  li->numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
        system("clear");
    }
    /*Pessoa aux;
    aux = li->dados[0];

    cout << aux.nome;*/
}