/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package strings;
import java.util.Scanner;
/**
 *
 * @author pc
 */
public class Strings {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scanf = new Scanner(System.in);
        String nome = "Fulano";
        String pedaco;
        pedaco = nome.substring(0,3); //Substrings do primeiro carcter até o terceiro
        // == "Ful"
        System.out.println("O tamanho do nome eh: "+ nome.length());
        char letra;
        letra = nome.charAt(5); // fornece a letra na 5° posição
        String nome2;
        nome2 = scanf.nextLine();
        if (nome2.equals(nome)) // operação == não funciona
            System.out.println("Voce digitou o mesmo nome");
    }
    
}
