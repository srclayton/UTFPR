#include "pessoa.h"
Pessoa::Pessoa(int inpDia, int inpMes, int inpAno){
        dia = inpDia;
        mes = inpMes;
        ano = inpAno;
    }
void Pessoa::calc_idade(int diaA, int mesA, int anoA){
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
int Pessoa::informaidd(){
    return idade;
}