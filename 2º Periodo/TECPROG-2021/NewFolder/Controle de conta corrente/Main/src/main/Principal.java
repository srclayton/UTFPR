/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.util.Scanner;

/**
 *
 * @author pc
 */
public class Principal {
    private static int escolha=1, tipoDeConta, dias;
    private static Scanner scanf = new Scanner(System.in);
    private static Conta conta;
    private static double valor;
    public static void executar(){
        while(escolha != 0){
            menu();
            escolha = scanf.nextInt();
            limparTela();
            if(escolha == 1){
                System.out.println("Digite 1 para conta corrente ou 2 para conta poupança");
                tipoDeConta = scanf.nextInt();
                if(tipoDeConta == 1)
                    conta = new ContaCorrente();
                else
                    conta = new ContaPoupanca();
            }else if(escolha == 2){
                System.out.println("Saldo em conta: R$" + conta.getSaldo());
            }else if(escolha == 3){
                System.out.println("Digite o valor desejado: R$");
                valor = scanf.nextDouble();
                if(conta.depositar(valor) == true)
                    System.out.println("Valor depositado!");
                else
                    System.out.println("Não foi possivel depositar!");
            }else if(escolha == 4){
                System.out.println("Digite o valor desejado: R$");
                valor = scanf.nextDouble();
                if(conta.sacar(valor) == true)
                    System.out.println("R$:" + valor + " sacado!");
                else
                    System.out.println("Não foi possivel sacar!");
            }else if(escolha == 5){
                System.out.println("Digite a quantidade de dias!");
                dias = scanf.nextInt();
                if(conta.aplicarJurosDiarios(dias) == true)
                    System.out.println("Juros aplicado!");
                else
                    System.out.println("Não foi possivel aplicar juros!");
            }
                
                
        }
    }
    private static void menu(){
        System.out.println("====================================");
        System.out.println("Digite a opção desejada!");
        System.out.println("1° Criar conta");
        System.out.println("2° Ler saldo");
        System.out.println("3° Depositar");
        System.out.println("4° Sacar");
        System.out.println("5° Aplicar juros");
        System.out.println("====================================");
    }
    private static void limparTela(){
        for(int i = 0; i<50; i++)
            System.out.println("\n");
    }
}
