/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stringabreviar;
import java.util.Scanner;
class Nomes{
    private String nome, nomeAbreviado="";
    
    public boolean setNome(String input){
        if(input.equals(null)||input.equals(" "))
            return false;
        else{
            nome = input;
            return true;
        }
    }
    
    
    public String getNomeAbreviado(){
        return nomeAbreviado;
    }
    
    
    public void abreviaNome(){
        char letra, aux;
        nome += " ";
        int tam = nome.length();
        
        for(int i=0,j=0,k=0;i<tam;i++,k++){
            letra = nome.charAt(i);
            if(letra == ' '){
                if(k>1 && k<5){
                    //nome com 3 letras cai nesse IF ex EVA
                   nomeAbreviado += " " + nome.substring(j,i); 
                }               
                else{                    
                    aux = nome.charAt(j);
                    if((int) aux > 96 && (int) aux < 123)
                    aux -= 32;
                    nomeAbreviado += " " + aux + ".";                    
                }
                    
                //if(i==0)
                    //nomeAbreviado += " " + nome.charAt(j);
                k=0;
                j=i+1;
            }
        }
    }
}
class Principal{
    private Nomes nome = new Nomes();
    private Scanner scanf = new Scanner(System.in);
    
    public void exe(){
        System.out.println("Ensira um nome:");
        if(nome.setNome(scanf.nextLine())){
            nome.abreviaNome();
            System.out.println(nome.getNomeAbreviado());
        }else
            System.out.println("Não foi possivel armazenar o nome!");
    }
}
/**
 *
 * @author pc
 */
public class StringAbreviar {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Principal iniciar = new Principal();
        iniciar.exe();
    }
    
}
