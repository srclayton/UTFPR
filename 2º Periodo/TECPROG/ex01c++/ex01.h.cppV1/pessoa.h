#include <stdio.h>
class Pessoa
{
    private:
    int idade, dia, mes, ano;
    // Esta é uma função construtora.
    // Uma construtora inicializa variáveis
    public:
    Pessoa(int inpDia, int inpMes, int inpAno){
        dia = inpDia;
        mes = inpMes;
        ano = inpAno;
    }

    // A função está dentro da estrutura ou struct
    void calc_idade(int diaA, int mesA, int anoA){
        int idd = anoA - ano;
        if (mes > mesA){
            idd -=1;
        }
        else{
            if (mes == mesA){
                if (dia > diaA){
                idd = idd - 1;
                }
            }
        }
    idade = idd; 
    }
    int informaidd(){
        return idade;
    }
};