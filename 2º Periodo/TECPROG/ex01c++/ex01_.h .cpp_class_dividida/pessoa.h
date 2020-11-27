#include <stdio.h>
class Pessoa{
    private:
    int idade, dia, mes, ano;

    public:
    Pessoa(int inpDia, int inpMes, int inpAno);
    void calc_idade(int diaA, int mesA, int anoA);
    int informaidd();
};