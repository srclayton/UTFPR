package novacalculadora;

public class CalcInterface {
    public double recebeOperando(int i){
        return 2;
    }
    public char recebeOperacao(){
        return 'c';
    }
    public void mostraResultado(double res){
        System.out.println("Resultado: " + res);
    }
}
