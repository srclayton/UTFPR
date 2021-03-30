
package calculadora;

public class CalcDados {
    private static int n1, n2;
    private static char operador;
    private static int resultado;
    
    
    public void setPrimNum(int num){
        n1 = num;
    }
    public void setSegNum(int num){
        n2 = num;
    }
    public void setOperador(char op){
        operador = op;
    }
    
    public static void operar(){
        switch (operador) {
            case '+':
                resultado = n1 + n2;
                break;
            case '-':
                resultado = n1 - n2;
                break;
            case '*':
                resultado = n1 * n2;
                break;
            default:
                resultado = n1 / n2;
                break;
        }
    }
    
    public static int getResultado(){
        return resultado;
    }
}
