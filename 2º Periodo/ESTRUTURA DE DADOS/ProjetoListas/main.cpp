#include "Lista.h"
int main(){
    /* //|||||||||||||||||TESTES LISTA ENCADEADA|||||||||||||||||||
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
    Lista_Seq* li_seq = cria_lista();
    //executar(1,li_seq);
    */
    /* |||||||||||||||||||TESTES LISTA SEQUENCIAL||||||||||||||||||
    //teste(lisEnc);
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
    escreve_arquivo(li);
    //abrir_e_ler_arquivo(li);
    //printaLista(li);*
    */
    Lista_Seq* li_seq = cria_lista(); // CRIO UMA LISTA DE CADA;
    //Lista* li_enc = cria_lista_encad();
    int escolha=1;
    while (escolha != 0)
    {
        menu();
        limpaBufferDoTeclado();
        cin >> escolha;
        system("clear");
        executar(escolha,li_seq);
    }
    apaga_lista(li_seq);
    return 0;
}

