#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct pessoas
{
    int idade, dia, mes, ano;
    
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
} Pessoa;

int main(){
    Pessoa einstein, newtom;
    einstein.dia = 14;
    einstein.mes = 3;
    einstein.ano = 1879;
    einstein.calc_idade(10,3,2020);
    
    newtom.dia = 4;
    newtom.mes = 1;
    newtom.ano = 1643;
    newtom.calc_idade(10,3,2020);

    cout << "Einstein: " << einstein.idade;
    cout << "Newtom: " << newtom.idade;
    return 0;
}