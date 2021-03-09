/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sistestacionamento;
import java.util.Scanner;
class Horario{
    private int hora,min;
    
    private int getHora(){
        return hora;
    }
    private int getMin(){
        return min;
    }
    public boolean setHora(int input){
        if(input >= 0 && input <= 24){
            hora = input;
            return true;
        }
        else{
            System.out.println("Horario invalido!");
            return false;
        }
    }
    public boolean setMin(int input){
        if(input >= 0 && input <= 60){
            min = input;
            return true;
        }
        else{
            System.out.println("minuto invalido!");
            return false;
        }
    }
    public int calcularIntervalo(Horario h){
         int aux=0;
         if(h.hora < this.hora){
             aux = (h.hora * 60)  + (this.hora * 60);
             h.hora = aux / 60;
         }
         aux = ((h.hora * 60) + h.min) - ((this.hora * 60) + this.min);
         return aux;       
    }
}
class Principal{
    private Horario entrada = new Horario(), saida = new Horario();
    private Scanner scanf = new Scanner(System.in);
    private int input, intervalo;
    private float valorAPagar;
    
    
    public void exe(){
        System.out.println("Ensira o horario de entrada sem dois postos':' ou virgula','. Exemplo 12:00 -> 1200");
        input = scanf.nextInt();
        if(entrada.setHora(input/100) == true){ // Armazena o as horas dividindo um inteiro por 100... e ja verifica se foi possivel alocar
            if(entrada.setMin(input%100) == true){ // Armazena os minutos pegando o resto da divizão por 100... e ja verifica se foi possivel alocar
                System.out.println("Ensira o horario de saida sem dois postos':' ou virgula','. Exemplo 12:00 -> 1200");
                input = scanf.nextInt();
                if(saida.setHora(input/100)== true){// Armazena o as horas dividindo um inteiro por 100... e ja verifica se foi possivel alocar
                    if(saida.setMin(input%100)== true){ // Armazena os minutos pegando o resto da divizão por 100... e ja verifica se foi possivel alocar
                        intervalo = entrada.calcularIntervalo(saida);
                        //System.out.println(intervalo);
                        calculaValorAPagar();
                        System.out.println("Valor:R$"+valorAPagar);
                    }
                }        
            }
        }
    }
    private void calculaValorAPagar (){
        if(intervalo <= 180){
            valorAPagar = (float) 4.50;
        }else if(intervalo > 180 && intervalo <= 720){
            int aux = intervalo - 180;
            aux /= 15;
            valorAPagar = (float) 4.50 + (aux * (float) 0.75);
        }else{
            valorAPagar = (float) 33.00;
        }
    }
}
/**
 *
 * @author pc
 */
public class SistEstacionamento {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Principal iniciar = new Principal();
        iniciar.exe();
    }
    
}
