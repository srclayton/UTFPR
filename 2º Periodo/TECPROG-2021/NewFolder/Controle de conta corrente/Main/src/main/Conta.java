package main;

import java.util.Random;


public abstract class Conta {
    protected double saldo=0;
    protected int numero;


    public boolean depositar(double valor){
        if(valor <= 0)
            return false;
        saldo += valor;
        return true;            
    }
    public double getSaldo(){
        return saldo;
    }
    public boolean sacar(double valor){
        if(valor > saldo)
            return false;
        saldo -= valor;
        return true;
    }
    public abstract boolean aplicarJurosDiarios(int dias);
}
