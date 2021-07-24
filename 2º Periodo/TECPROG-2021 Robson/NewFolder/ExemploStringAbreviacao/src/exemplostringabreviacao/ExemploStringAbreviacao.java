/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplostringabreviacao;
import java.util.Scanner;
class Nomes{
    private String nome, nomeAbreviado;
    
    
    public boolean  setNome(String input){
        if(input != null){
            nome = input;
            return true;
        }
        else{
            System.out.println("Não foi possivel salvar o nome!");
            return false;
        }
    }
    public String retornaNome(){
        return nome;
    }
    
}
class Principal{
    private Scanner scanf = new Scanner(System.in);
    private Nomes name = new Nomes();
    private int tamanho,i;
    
    
    
}
/**
 *
 * @author pc
 */
public class ExemploStringAbreviacao {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
