
package calculadora;

public  class CalcControle {
    private static CalcDados dados = new CalcDados();
    public static void executar(){
        CalcInterface.menu();
        dados.setPrimNum(CalcInterface.getPrimNum());
        dados.setSegNum(CalcInterface.getSegNum());
        dados.setOperador(CalcInterface.getOperador());
        if(CalcInterface.getOperador() != 's' || CalcInterface.getOperador() != 'S'){
            CalcDados.operar();
            CalcInterface.mostraResultado();
        }else
            System.exit(0);
            
    }
}
