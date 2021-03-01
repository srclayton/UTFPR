/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package exer01sistemadetransporte;
import java.util.Scanner;
class Caixa{
    private double largura,altura,profundidade;
    //Declaração dos atributos de maneira Private pois os mesmos só seram acessados dentro da classe
    public void setLargura(double input){
        largura = input;
    }//Metodo publico pois sera acessado/chamado fora da classe Caixa
    public void setAltura(double input){
        altura = input;
    }//Metodo publico pois sera acessado/chamado fora da classe Caixa
    public void setProfundidade(double input){
        profundidade = input;
    }//Metodo publico pois sera acessado/chamado fora da classe Caixa
    public void calculaAreaExt(){
        System.out.println("Area: " + 2*((largura*altura)+(largura*profundidade)+(altura*profundidade)));
    }//Metodo publico pois sera acessado/chamado fora da classe Caixa
    public void calculaVolume(){
        System.out.println("Volume: " +  largura*altura*profundidade);
    }//Metodo publico pois sera acessado/chamado fora da classe Caixa
        
}
class ExTestadorDeCaixa{
    private Caixa box1 = new Caixa(), box2 = new Caixa();
    private Scanner scanf = new Scanner(System.in);
    private double valor;
    public void exec(){
        preenche(box1);
        box1.calculaAreaExt();
        box1.calculaVolume();
        preenche(box2);
        box2.calculaAreaExt();
        box2.calculaVolume();
    }//Metodo publico pois sera acessado/chamado fora da classe ExTestadorDeCaixa
    
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
    }//Metodo privado pois não ha nescessidade de ser acessado/chamado fora da classe ExTestadorDeCaixa
    
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
