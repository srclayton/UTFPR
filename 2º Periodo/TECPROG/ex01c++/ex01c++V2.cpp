#include<stdio.h>
#include<iostream>
using namespace std;
struct Pessoa
{
    int idade, dia, mes, ano;
    // Esta é uma função construtora.
    // Uma construtora inicializa variáveis
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
};

int main(){
    Pessoa einstein(14,3,1879);
    Pessoa newtom(4,1,1643);
    
    einstein.calc_idade(10,03,2020);
    newtom.calc_idade(10,3,2020);

    cout << "Einstein: " << einstein.idade;
    cout << "Newtom: " << newtom.idade;
    return 0;
}