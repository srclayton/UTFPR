#include <iostream>
#include <new>
using namespace std;

int main(){
    int i,n,*p;
    cout << "Quantos numeros deseja adicionar? ";
    cin >> i;
    p=new(nothrow)int[i];
    if(p==nullptr)
        cout << "** Erro: Memoria Insuficiente";
    else{
        for(n=0;n<i;n++){
            cout << "Entre com um numero ";
            cin >> p[n];
        }
        cout << "Você digitou ";
        for(n=0;n<i;n++)
            cout << p[n] << ",";
        delete []p;   
    }
    return 0;
}