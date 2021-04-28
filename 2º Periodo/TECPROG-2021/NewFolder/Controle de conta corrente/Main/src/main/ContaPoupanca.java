package main;
public class ContaPoupanca extends Conta {

    @Override
    public boolean aplicarJurosDiarios(int dias) {
        if(saldo > 1000){
            double aux = saldo - 1000;
            saldo -= aux;
            for (int i = 0; i< dias; i++)
                aux = aux + (aux * 0.02);
            saldo += aux;
            return true;
        }else
            return false;
    }
    
}
