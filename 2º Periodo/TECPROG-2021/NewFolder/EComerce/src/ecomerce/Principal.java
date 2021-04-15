package ecomerce;

import java.util.Scanner;

public  class Principal {
    private static CarrinhoDeCompras carrinho = new CarrinhoDeCompras();
    private static String nome;
    private static int qnt;
    private static float valor;
    private static Scanner scanf = new Scanner(System.in);

    public static void executar(){
        int escolha =1 ;
        while(escolha != 0){
            menu();
            escolha = scanf.nextInt();
            if(escolha == 1){
                preenche();
                Item item = new Item(nome, valor, qnt);
                if(carrinho.adicionarItem(item)!=true)
                    System.out.println("Não foi possivel adicionaro item!");
                limpaTela();                
            }else if(escolha == 2){
                preenche();
                Item item = new Item(nome, valor, qnt);
                if(carrinho.removerItem(item)!=true)
                    System.out.println("Não foi possivel remover o item!");
                limpaTela();
            }else if(escolha == 3){
                System.out.println("Seu valor total é: "+ carrinho.getValorTotal());
            }else if(escolha == 0)
                System.exit(0);
            else
                System.out.println("Digite uma opção valida");     
        }
    }
    private static void menu(){
        System.out.println("===============================================");
        System.out.println("Olá digite o numero desejado de sua opção");
        System.out.println("1° Adicionar item ");
        System.out.println("2° Remove item");
        System.out.println("3° Valor toal");
        System.out.println("0° Para sair.");
        System.out.println("===============================================");
    }
    private static void preenche(){
        System.out.println("Informe o nome do item:");
        nome = scanf.nextLine();
        scanf.nextLine();
        System.out.println("Infome a quantidade:");
        qnt = scanf.nextInt();
        scanf.nextLine();
        System.out.println("Informe o valor:");
        valor = scanf.nextFloat();
        scanf.nextLine();
    }    
    private static void limpaTela(){
        for (int i=0; i<50; i++){
            System.out.println();
        }
    }
}
