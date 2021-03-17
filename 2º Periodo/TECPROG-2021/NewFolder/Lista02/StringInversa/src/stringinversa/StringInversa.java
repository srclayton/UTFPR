/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stringinversa;
import java.util.Scanner;

class StringInverse{
    private String frase, fraseInver="";
    
    public String getFrase(){   
        return fraseInver;
    }
    
    public boolean setFrase(String input){
        if(input.equals(null) || input.equals("")){
            System.out.println("Não foi possivel armazenar a frase!");
            return false;
        }else{
            frase = input;
            return true;
        }
    }  
    /* METODO inverteFrase
    --------------------------------------------------------------------------------------------------------
    este metodo percorre toda a string letra por letra começando de seu final para o inicio. 
    percorro toda string procurando um espaço " " caso a ache, pego sua substringo no intervalo i=(n) e j=(m)
    e concateno esta substring na variavel fraseInver.
    --------------------------------------------------------------------------------------------------------
    */
    public void inverteFrase(){
        String aux = frase;
        char letra;
        int tam=aux.length();
        for(int i =tam-1,j=tam;i>=0;i--){
            letra = aux.charAt(i);
            if(letra == ' '){
                fraseInver += aux.substring(i,j);
                //System.out.println(i + aux.substring(i,j));
                j=i;
            }else if(i==0){
                //System.out.println(i + aux.substring(i,j));
                fraseInver += " " + aux.substring(i,j);
            }            
        }
    }
}

class Principal{
    StringInverse texto = new StringInverse();
    Scanner scanf = new Scanner(System.in);
    
    public void exe(){
        System.out.println("Informe a frase desejada:");
        if(texto.setFrase(scanf.nextLine())){
            texto.inverteFrase();
            System.out.println(texto.getFrase());
        }                    
    }
}

/**
 *
 * @author pc
 */
public class StringInversa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Principal iniciar = new Principal();
        iniciar.exe();
    }
}
