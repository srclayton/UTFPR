package lista04email;
import java.util.Scanner;

public class Lista04Email {
    public static void main(String[] args) {
       Email email = new Email();
       Scanner scanf = new Scanner(System.in);
       System.out.println("Infome o assunto do email:");
       email.setConteudoAssunto(scanf.nextLine());
       System.out.println("Informe a mensagem:");
       email.addTextoMensagem(scanf.nextLine());
       
       email.mostraDados();
    }
    
}
