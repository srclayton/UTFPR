package principal;

import java.util.Scanner;

public class Principal {
    private static int escolha=1;
    private static String nomeaux;
    private static int cpfaux;
    private static Scanner scanf = new Scanner(System.in);

    public static void main(String[] args) {

        while(escolha != 0){
            menu();
            escolha = scanf.nextInt();
           if(escolha == 1){
               preenche();
               Faxineiro pessoa = new Faxineiro(nomeaux, cpfaux);
               limparTela();
               pessoa.mostraDados();
               System.out.println("Salario do mês: " + pessoa.calculaSalario(176));
           }
               
        }
    }
    private static void menu(){
        System.out.println("==========================================");
        System.out.println("    Digite o numero da opção desejada!");
        System.out.println("    1 Inserir Faxineiro;");
        System.out.println("    2 Inserir Gerente;");
        System.out.println("    3 Inserir Empregado;");
        System.out.println("    0 Para sair;");        
        System.out.println("==========================================");
    }
    private static void preenche(){
        System.out.println("Informe o nome: ");
        nomeaux = scanf.nextLine();
        scanf.nextLine();
        System.out.println("Informe o cpf: ");
        cpfaux = scanf.nextInt();
        scanf.nextLine();
    }
    private static void limparTela(){
        for(int i = 0; i < 50; i++)
            System.out.println("\n");
    }
}
