#include <iostream>
#include <new>
using namespace std;
int main ()
{
int i,n;
int * p;
cout << "Quantos numeros voce quer? ";
cin >> i;
p= new (nothrow) int[i];
if (p == nullptr)
cout << "** Erro: Memoria Insuficiente ";
else
{
for (n=0; n<i; n++)
{
cout << "Entre um numero: "; cin >> p[n];
}
cout << "Voce digitou: ";
for (n=0; n<i; n++) cout << p[n] << ", ";
delete[] p;
}
return 0;
}