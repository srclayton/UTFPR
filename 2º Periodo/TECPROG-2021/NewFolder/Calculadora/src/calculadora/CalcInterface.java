/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculadora;
import java.util.Scanner;

public  class CalcInterface {
    private static int n1, n2, result;
    private static String escolha;
    private static Scanner scanf = new Scanner(System.in);
    
    public static void menu(){
        System.out.println("Digite '-' para subitração \n"
                         + "Digite '+' para adição\n"
                         + "Digite '*' para multiplicação\n"
                         + "Digite '/' para divisão\n"
                         + "Ou digite 's' para sair!");
        escolha = scanf.nextLine();       
        System.out.println("Informe o primeiro valor");
        n1 = scanf.nextInt();
        System.out.println("Informe o segundo valor");
        n2 = scanf.nextInt();

    }
    public static int getPrimNum(){
        return n1;
    }
    public static int getSegNum(){
        return n2;
    }
    public static char getOperador(){
        char aux = escolha.charAt(0);
        return aux;
    }
    public static void mostraResultado(){
        result = CalcDados.getResultado();
        System.out.println("O resultado é: "+result);
    }
}
