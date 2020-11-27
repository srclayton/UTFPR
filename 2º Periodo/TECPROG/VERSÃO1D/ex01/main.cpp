#include <stdio.h>
#include "pessoa.h"
#include <iostream>
using namespace std;
int main(){
    Pessoa einstein(14,3,1879);
    Pessoa newtom(4,1,1643);

    einstein.calc_idade(10,03,2020);
    newtom.calc_idade(10,3,2020);

    cout << "Einstein: " << einstein.informaidd() << endl;
    cout << "Newtom: " << newtom.informaidd();
    return 0;
}
