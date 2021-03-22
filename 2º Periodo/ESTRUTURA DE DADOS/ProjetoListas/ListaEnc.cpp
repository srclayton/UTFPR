#include <string>
#include "ListaEnc.h" //inclui os Prot�tipos
using namespace std;
struct lista_enc{
    struct pessoa_enc dados;
    struct lista_enc *prox;
};
typedef struct lista_enc ListaEnc;

Lista* cria_lista_encad(){
    Lista* li = new Lista;
    if(li != NULL)
        *li = NULL;
    return li;
}
void apaga_lista_encad(Lista* li){
    if(li != NULL){
        ListaEnc* aux;
        while((*li) != NULL){ //enquanto o proximo não for nulo, se for nulo ja não existe mais elementos;
            aux = *li; // minha variavel aux recebe o dado inicial;
            *li = (*li)->prox; // logo meu dado inicial ira apontar para o proximo dado;
            free(aux); // libero meu antigo dado inicial;
        }
        free(li);
    }
}
bool adiciona_lista_enc_final(Lista* li, PessoaEnc dado, int* nCompa, int* nCopi){
    if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc *novoDado = new ListaEnc;
    if(novoDado == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    novoDado->dados = dado;
    novoDado->prox = NULL;
    if((*li) == NULL){// verifico se há algum dado na minha lista incial, caso não tenha apenas aloco o dado pois sera meu primeiro dado;
        *nCompa = *nCompa + 1;
        *li = novoDado;
    }else{
        ListaEnc *aux; // declaro uma variavel auxiliar para nunca perder o começo da lista na operação ->prox;
        aux = *li;
        while(aux->prox != NULL){ // percorro toda minha lista até chegar no ultimo dado: ->prox==null, sendo assim atualizo minha lista inserindo um dado na ultima posição;
            aux = aux->prox;
            *nCopi = *nCopi + 1;
        }
        aux->prox = novoDado;
    }
    return 1;
}
bool adiciona_lista_enc_inicio(Lista* li, PessoaEnc dado, int* nCompa, int* nCopi){
    if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc* novoDado = new ListaEnc;
    if(novoDado == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    novoDado->dados = dado;
    novoDado->prox = (*li);
    *li = novoDado;
    return 1;
}
bool adiciona_lista_enc_n_posicao(Lista* li, PessoaEnc dado, int posicao, int* nCompa, int* nCopi){
    if(li == NULL)
    return 0;
    *nCompa = *nCompa + 1;
    ListaEnc* novoDado = new ListaEnc;
    if(novoDado == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    novoDado->dados= dado;
    if(posicao > tamanho_lista(li, nCompa, nCopi))
        return 0;
    int i;
    ListaEnc* ant, *atual = *li;
    for(i=0; i< posicao-1; i++){
        ant = atual;
        *nCopi = *nCopi +1;
        atual = atual->prox;
        *nCopi = *nCopi +1;
        //cout << atual->dados.nome << "\n";
        //cout << atual->dados.nome << cout << atual->dados.rg << endl;
    }
    novoDado->prox = atual;
    *nCopi = *nCopi +1;
    ant->prox = novoDado;
    return 1;
}
bool remove_lista_enc_inicio(Lista* li, int* nCompa, int* nCopi){
    if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    if((*li) == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc *aux = *li;
    *li = aux->prox; //a faço minha lista receber o segundo dado;
    free(aux);//libero meu primeiro dado;
    return 1;
}
bool remove_lista_enc_final(Lista* li, int* nCompa, int* nCopi){
    if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    if((*li) == NULL)//lista vazia
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc *ant, *aux = *li; //crio duas variaveis auxiliares; uma para receber minha lista, e assim percorres toda ela, e uma outra lista para receber o dado antescessor da lista aux;
    while(aux->prox != NULL){ //quando minha variavel aux chega em null, ou seja ultimo dado, minha variavel ant esta no penultimo dado;
        ant = aux;            //logo em seguida eu libero meu ultimo dado;
        *nCopi = *nCopi +1;
        aux = aux->prox;
        *nCopi = *nCopi +1;
    }

    if(aux == (*li))
        *li = aux->prox;
    else
        ant->prox = aux->prox;
    *nCompa = *nCompa + 1;
    free(aux);
    return 1;
}
bool remove_lista_enc_n_posicao(Lista* li, int posicao, int* nCompa, int* nCopi){
    if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    if((*li) == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc* ant, *atual = *li;
    for(int i=0; i< posicao-1; i++){
        ant = atual;
        *nCopi = *nCopi +1;
        atual = atual->prox;
        *nCopi = *nCopi +1;
        //cout << atual->dados.nome << "\n";
        //cout << atual->dados.nome << cout << atual->dados.rg << endl;
    }
    ant->prox = atual->prox;
    *nCopi = *nCopi +1;
    free(atual);
    return 1;
}
bool procura_rg_enc(Lista* li, int inputRg, int* nCompa, int* nCopi){
    if(li== NULL)
        return 0;
    *nCompa = *nCompa + 1;
    if((*li)==NULL)
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc* ant, *atual = *li;
    int i=0;
    while(atual!=NULL && atual->dados.rg != inputRg){
        atual = atual->prox;
        i++;        
        *nCopi = *nCopi +1;
    }
        if(atual != NULL){
            cout << "NOME:"<< atual->dados.rg << ", RG:"<< atual->dados.nome << " Posição:" << i <<"    ";
            *nCompa = *nCompa + 1;
            return 1;
        }
        else
            return 0;
    //cout << "NOME:"<< li->dados[k].rg << ", RG:"<< li->dados[k].nome << "    ";
}
int tamanho_lista(Lista* li, int* nCompa, int* nCopi){
    if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    int cont = 0;
    ListaEnc* aux = *li;
    while(aux != NULL){ //apenas percorro minha lista em uma variavel auxiliar para contar seu tamanho;
        cont++;
        aux = aux->prox;
        *nCopi = *nCopi +1;
    }
    return cont;
}
bool imprime_lista(Lista* li, int* nCompa, int* nCopi){
     if(li == NULL)
        return 0;
    *nCompa = *nCompa + 1;
    ListaEnc* aux = *li;
    while(aux != NULL){ // percorro novamente minha lista utilizando uma variavel auxiliar e printando seus dados;
        cout << aux->dados.nome << ", "<< aux->dados.rg <<"\n";  
        aux = aux->prox;
        *nCopi = *nCopi +1;
    }
    return 1;
}
void escreve_arquivo_enc(Lista* li, int* nCompa, int* nCopi){
    ListaEnc* aux = *li;
    ofstream myfile("src/ListaEscrita.txt");
    if(myfile.is_open()){
        *nCompa = *nCompa + 1;
        while(aux != NULL){ //mesma logica de printar a lista utilizo para escreve-la em um arquivo, pecorro minha lista escrevendo dado por dado um arquivo.txt;
        myfile << aux->dados.nome << "," << aux->dados.rg << "\n";
        aux = aux->prox;
        *nCopi = *nCopi +1;
    }
        cout << "Lista salva com sucesso!";   
    }else
        cout << "Não foi possivel salvar o arquivo!";
}
void abrir_e_ler_arquivo_enc(Lista* li, int* nCompa, int* nCopi){
    string linha, inputNome, rgString;
    int inputRg, tamLinha, localizaEspaco=0, k , aux;
    bool retorno;
    PessoaEnc atual;

    
    ifstream myfile(NOME_ARQUIVO);
    if(myfile.is_open()){
        while (getline(myfile,linha))
        {
            localizaEspaco = linha.find(",");//Localiza a primeira virgula;
            tamLinha = linha.size(); // tamanho da linha;
            inputNome=linha.substr(0,localizaEspaco);//string até a virgula;
            rgString= linha.substr(localizaEspaco+1,tamLinha);// recebo o rg;
            inputRg= stoi(rgString);
            atual.nome= inputNome;
            atual.rg= inputRg;
            retorno = adiciona_lista_enc_final(li,atual, nCompa, nCopi);
            if(retorno!= 0){
                cout << "Não foi possivel adicionar todos dados, memoria  cheia.";
                myfile.close();
            }
        }
        cout << "Lista aberta com sucesso!";   
    }else
        cout << "Não foi possivel abir o arquivo!";
}
void limpaBufferListaEnc(){
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
    cout << "\n|9- Salvar a lista em um arquivo;              |";
    cout << "\n|10- Ler uma lista de dados;                   |";
    cout << "\n|0- Para sair do programa;                     |";
    cout << "\n|             LISTA ENCADEADA                  |";
    cout << "\n================================================\n";
}
