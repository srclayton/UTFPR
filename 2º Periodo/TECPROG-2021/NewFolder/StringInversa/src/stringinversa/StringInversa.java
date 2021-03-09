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
        return frase;
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
    public void inverteFrase(){
        String aux = frase;
        char letra;
        int tam=aux.length();
        for(int i =tam-1,j=0;i>0;i--){
            letra = aux.charAt(i);
            if(letra == ' '){
                //fraseInver += aux.substring(j,i);
                System.out.println(aux.substring(j,i));
                i=j;
            }
            
        }
        System.out.println(fraseInver);
    }
}

class Principal{
    StringInverse texto = new StringInverse();
    Scanner scanf = new Scanner(System.in);
    
    public void exe(){
        System.out.println("Informe a frase desejada:");
        if(texto.setFrase(scanf.nextLine())){
            texto.inverteFrase();
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
