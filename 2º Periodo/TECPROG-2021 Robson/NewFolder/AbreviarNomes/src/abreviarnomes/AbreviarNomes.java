/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package abreviarnomes;
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
        char letra,lAux;
        int tam = nome.length(),aux=0;
        for(int i=0,j=0,k=0;i<tam;i++){
            letra = nome.charAt(i);
            if(letra == ' '){
                while(aux != 0){
                    lAux = nome.charAt(i++);
                    if(lAux != ' ')
                        k++;
                }
                if(k>0&&k<4)
                    nomeAbreviado += nome.substring(i,k);
                else
                    nomeAbreviado +=nome.substring(i,j);
                j=i;
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
public class AbreviarNomes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Principal iniciar = new Principal();
        iniciar.exe();
    }
    
}
