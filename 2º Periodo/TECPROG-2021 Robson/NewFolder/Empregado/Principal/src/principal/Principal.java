package principal;

import java.util.Scanner;

public class Principal {
    private static int escolha=1;
    private static String nomeaux;
    private static int cpfaux, horasT;
    private static Scanner scanf = new Scanner(System.in);

    public static void main(String[] args) {

        while(escolha != 0){
            menu();
            escolha = scanf.nextInt();
           if(escolha == 1){ // Faxineiro;
               preenche();
               Faxineiro pessoa = new Faxineiro(nomeaux, cpfaux);
               limparTela();
               pessoa.mostraDados();
               System.out.println("Salario do mês: " + pessoa.calculaSalario(horasT));
           }else if(escolha == 2){ // Gerente;
               int bonusaux;
               System.out.println("Informe o bonus: ");
               bonusaux= scanf.nextInt();
               preenche();
               Gerente pessoa = new Gerente(nomeaux, cpfaux, bonusaux);
               limparTela();
               pessoa.mostraDados();
               System.out.println("Salario do mês: " + pessoa.calculaSalario(horasT));
           }else if(escolha == 3){ // Empregado
               String cargo;
               preenche();
               System.out.println("Digite o cargo: ");
               cargo = scanf.nextLine();
               //scanf.nextLine();
               Empregado pessoa = new Empregado(nomeaux, cargo, cpfaux);
               limparTela();
               pessoa.mostraDados();
               System.out.println("Salario do mês: " + pessoa.calculaSalario(horasT));
           }else
               System.out.println("Entre com uma opção valida!");              
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
        System.out.println("Informe o cpf: ");
        cpfaux = scanf.nextInt();
        scanf.nextLine();
        System.out.println("Informe o numero de horas trabalhadas: ");
        horasT = scanf.nextInt();
        scanf.nextLine();
        System.out.println("Informe o nome: ");
        nomeaux = scanf.nextLine();
        //scanf.nextLine();     
    }
    private static void limparTela(){
        for(int i = 0; i < 50; i++)
            System.out.println("\n");
    }
}
