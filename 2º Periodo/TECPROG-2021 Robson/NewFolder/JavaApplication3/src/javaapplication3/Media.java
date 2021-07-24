/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;
import java.util.Scanner; 
/**
 *
 * @author pc
 */
public class Media {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scanf = new Scanner(System.in);
        int []nota = new int[5];
        int i,alunos_med=0;
        for(i=0;i<5;i++){
            System.out.println("Digite a nota: ");
            nota[i] = scanf.nextInt();
            if(nota[i] >= 6)
                alunos_med++;
        }
        if(alunos_med > 0)
            System.out.println(alunos_med+" Alunos na media.");
        else
            System.out.println("Não a alunos na media.");
    }
    
}
