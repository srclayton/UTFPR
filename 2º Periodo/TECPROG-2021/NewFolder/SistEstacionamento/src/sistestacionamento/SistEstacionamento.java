/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sistestacionamento;
import java.util.Scanner;
class Horario{
    private int hora,min;
    
    public boolean setHora(int input){ //Metodo para armazenar as horas de entrada! verifica se as horas estão no intervalo 01h à 24h, caso contrario retorna um bool falso.
        if(input > 0 && input <= 24){
            hora = input;
            return true;
        }
        else{
            System.out.println("Horario invalido!");
            return false;
        }
    }
    public boolean setMin(int input){//Metodo para armazenar os minutos de entrada! verifica se os minutos estão no intervalo 0min à 60min, caso contrario retorna um bool falso.
        if(input >= 0 && input <= 60){
            min = input;
            return true;
        }
        else{
            System.out.println("minuto invalido!");
            return false;
        }
    }
    /*---------------------------------------------------------------------------
    Caso o cliente saia depois das 24h ha de se calcular um "novo horario de entrada"
    Exemplo: Caso o cliente entre as 24h. e saia as 06h. da manhã, faço o seguinte calculo:
                      360  +  1440 = 1800  <----------novo horario de saida;
    horario de saida --^    +    ^-- horario de entrada
    em seguida faço o novo horario de saida - horaio de entrada = 360 minutos (6h.)     
    ----------------------------------------------------------------------------*/
    public int calcularIntervalo(Horario h){
         int aux=0;
         if(h.hora < this.hora){ // caso o cliente entre as 24h. e saia as 06h da manhã, faço o seguinte calculo p
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
        }else if(intervalo > 180 && intervalo <= 720){ //os minutos excedentes a cada 15min.
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
