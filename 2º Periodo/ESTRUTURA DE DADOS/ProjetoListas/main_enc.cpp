#include "ListaEnc.h"
void executar_enc(Lista* li,int escolha);
int main(){
   Lista* li = cria_lista_encad();
   int posicao, escolha=1, inputRg;
   int numDeCompa=0, numDeCopi=0;
   PessoaEnc inputDado;
   bool retorno;
   clock_t inicioDaFuncao, finalDaFuncao;
   long double tempoDeExecucao;
   while (escolha != 0)
   {
       menu();
       limpaBufferListaEnc();
       cin >> escolha;
       system("clear");
       if(escolha <= 10){
           if(escolha ==1){
                limpaBufferListaEnc();
                cout << "\nDigite o nome desejado:";
                cin >> inputDado.nome;
                limpaBufferListaEnc();
                cout << "\nDigite o RG:";
                cin >> inputDado.rg;
                inicioDaFuncao = clock();
                retorno = adiciona_lista_enc_inicio(li, inputDado, &numDeCompa, &numDeCopi);
                if(!retorno){
                    cout << "ATENÇÃO      ";
                    cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
                }else{
                    cout << "ATENÇÃO      ";
                    cout << "Dado adicionado com sucesso!."; 
                }
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
           }else if(escolha ==2){ // INSERE UM DADO NO FINAL DA LISTA
                limpaBufferListaEnc();
                cout << "\nDigite o nome desejado:";
                cin >> inputDado.nome;
                limpaBufferListaEnc();
                cout << "\nDigite o RG:";
                cin >> inputDado.rg;
                inicioDaFuncao = clock();
                retorno = adiciona_lista_enc_final(li, inputDado, &numDeCompa, &numDeCopi);
                if(!retorno){
                    cout << "ATENÇÃO      ";
                    cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
                }else{
                    cout << "ATENÇÃO      ";
                    cout << "Dado adicionado com sucesso!."; 
                }       
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";    
                system("clear");        
            }else if(escolha ==3){ // INSERE UM DADO NA N POSIÇÃO DA LISTA
                limpaBufferListaEnc();
                cout << "\nDigite o nome desejado:";
                cin >> inputDado.nome;
                limpaBufferListaEnc();
                cout << "\nDigite o RG:";
                cin >> inputDado.rg;
                limpaBufferListaEnc();
                cout << "\nDigite a posição:";
                cin >> posicao;
                inicioDaFuncao = clock();
                retorno = adiciona_lista_enc_n_posicao(li, inputDado, posicao, &numDeCompa, &numDeCopi);
                if(!retorno){
                    cout << "ATENÇÃO      ";
                    cout << "Não foi possivel armazenar os dados, memoria indisponivel.";    
                }else{
                    cout << "ATENÇÃO      ";
                    cout << "Dado adicionado com sucesso!."; 
                }  
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==4){ // REMOVE UM DADO NO INICIO DA LISTA
                inicioDaFuncao = clock ();
                retorno = remove_lista_enc_inicio(li, &numDeCompa, &numDeCopi);
                if(!retorno)
                    cout << "Não foi possivel remover.";
                else
                    cout << "Dado retirado com sucesso!";
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==5){ // REMOVE UM DADO NO FINAL DA LISTA
                inicioDaFuncao = clock();
                retorno = remove_lista_enc_final(li, &numDeCompa, &numDeCopi);
                if(!retorno)
                    cout << "Não foi possivel remover.";
                else    
                    cout << "Dado retirado com sucesso!";
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==6){ // REMOVE UM DADO NA N POSIÇÃO DA LISTA
                limpaBufferListaEnc();
                cout << "\nDigite a posição:";
                cin >> posicao;
                inicioDaFuncao = clock();
                retorno = remove_lista_enc_n_posicao(li, posicao, &numDeCompa, &numDeCopi);
                if(!retorno)
                    cout << "Não foi possivel remover.";
                else
                    cout << "Dado retirado com sucesso!";
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==7){ // FAZ A BUSCA DE UM RG NA LISTA
                limpaBufferListaEnc();
                cout << "\nDigite o RG:";
                cin >> inputRg;
                inicioDaFuncao = clock();
                retorno = procura_rg_enc(li, inputRg, &numDeCompa, &numDeCopi);
                if(!retorno)
                    cout << "Não foi possivel encontrar este RG.";
                finalDaFuncao = clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==8){
                inicioDaFuncao = clock();
                retorno = imprime_lista(li, &numDeCompa, &numDeCopi);
                if(!retorno)
                    cout << "Não foi possivel mostrar a lista.";
                finalDaFuncao = clock();
                finalDaFuncao = clock();
                tempoDeExecucao= finalDaFuncao - inicioDaFuncao;
                sleep(4);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==9){
                inicioDaFuncao= clock();
                escreve_arquivo_enc(li, &numDeCompa, &numDeCopi);
                finalDaFuncao= clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }else if(escolha ==10){
                inicioDaFuncao = clock();
                abrir_e_ler_arquivo_enc(li, &numDeCompa, &numDeCopi);
                finalDaFuncao= clock();
                tempoDeExecucao = (finalDaFuncao - inicioDaFuncao);
                cout << "C(n):" << numDeCompa << "  |  " << "M(n):" <<  numDeCopi <<  "Tempo de Execução:" << tempoDeExecucao << "  Nanoseconds";
                system("clear");
            }
       }else{
           cout << "Escolha uma opção valida!";
       }
       
   }

    /*//|||||||||||||||||TESTES LISTA ENCADEADA|||||||||||||||||||
    PessoaEnc x, y, z, h, i, j,k;
    x.nome="DANIEL";
    x.rg=123456;
    y.nome="JUNIOR";
    y.rg=77778;
    z.nome="KENNEDY";
    z.rg=777;
    h.nome="lucas";
    h.rg=88;
    i.nome="alberto";
    i.rg=5555;
    j.nome="jason";
    j.rg=6666;
    k.nome="caralho";
    k.rg=6666;
    Lista* li = cria_lista_encad();
    adiciona_lista_enc_inicio(li,x);
    adiciona_lista_enc_final(li,y);
    adiciona_lista_enc_final(li,z);
    adiciona_lista_enc_inicio(li,h);
    adiciona_lista_enc_final(li,i);
    adiciona_lista_enc_inicio(li,j);
    adiciona_lista_enc_n_posicao(li,k,3);
    //procura_rg_enc(li,6666);
    //remove_lista_enc_inicio(li);
    //remove_lista_enc_final(li);
    //remove_lista_enc_n_posicao(li,6);
    abrir_e_ler_arquivo_enc(li);
    escreve_arquivo_enc(li);
    imprime_lista(li);

    apaga_lista_encad(li);
    //Lista_Seq* li_seq = cria_lista();
    //executar(1,li_seq);*/
    apaga_lista_encad(li);
    return 0;
    
}

