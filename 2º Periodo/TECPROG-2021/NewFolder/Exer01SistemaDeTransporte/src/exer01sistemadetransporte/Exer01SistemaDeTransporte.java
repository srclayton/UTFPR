/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package exer01sistemadetransporte;
import java.util.Scanner;
class Caixa{
    private double largura,altura,profundidade;
    
    public void setLargura(double input){
        largura = input;
    }
    public void setAltura(double input){
        altura = input;
    }
    public void setProfundidade(double input){
        profundidade = input;
    }
    public void calculaAreaExt(){
        System.out.println("Area: " + 2*((largura*altura)+(largura*profundidade)+(altura*profundidade)));
    }
    public void calculaVolume(){
        System.out.println("Volume: " +  largura*altura*profundidade);
    }
        
}
class ExTestadorDeCaixa{
    private Caixa box1 = new Caixa(), box2 = new Caixa();
    private Scanner scanf = new Scanner(System.in);
    private int i;
    private double valor;
    public void exec(){
        preenche(box1);
        box1.calculaAreaExt();
        box1.calculaVolume();
        preenche(box2);
        box2.calculaAreaExt();
        box2.calculaVolume();
    }
    
    private void preenche(Caixa box){
            System.out.println("Digite a largura da caixa: ");
            valor = scanf.nextDouble();
            box.setLargura(valor);
            System.out.println("Digite a altura da caixa: ");
            valor = scanf.nextDouble();
            box.setAltura(valor);
            System.out.println("Digite a profundidade da caixa: ");
            valor = scanf.nextDouble();
            box.setProfundidade(valor);           
    }
    
}
/**
 *
 * @author pc
 */
public class Exer01SistemaDeTransporte {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ExTestadorDeCaixa iniciar = new ExTestadorDeCaixa();
        iniciar.exec();        
    }
    
}
