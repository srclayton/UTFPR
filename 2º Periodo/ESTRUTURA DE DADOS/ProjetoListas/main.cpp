#include <iostream>
#include "Lista.h"
using namespace std;
int main()
{
    Lista *li = cria_lista();
    int escolha=1;
    while (escolha!=0){
        menu();
        limpaBufferDoTeclado();
        cin >> escolha;
        system("clear");
        executar(escolha, li);
    }
    

    /*Pessoa x, y, z, h, i, j;
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
    adiciona_lista_inicio(li,x);
    adiciona_lista_final(li,y);
    adiciona_lista_final(li,h);
    adiciona_lista_final(li,i);
    adiciona_lista_final(li,j);
    adiciona_lista_n_posicao(li,z,1);
    printaLista(li);
    int posicaoRg;
    posicaoRg = procura_rg(li,88);
    escreve_arquivo(li);*/
    //abrir_e_ler_arquivo(li);
    //printaLista(li);

    return 0;
}



