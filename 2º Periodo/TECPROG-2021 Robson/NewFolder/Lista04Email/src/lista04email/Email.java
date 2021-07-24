
package lista04email;

public class Email {
    private Assunto assunto = new Assunto();
    private Mensagem mensagem = new Mensagem();
    
    public void setConteudoAssunto(String texto){
        if(assunto.setAssunto(texto) != true)
            System.out.println("Não foi possivel adicionar o assunto.");
        else
            System.out.println("Assunto adicionado.");
    }
    public void addTextoMensagem(String texto){
        if(mensagem.addMensagem(texto) != true)
            System.out.println("Não foi possivel adicionar mensagem.");
        else
            System.out.println("Mensagem adicionada.");
    }
    public void mostraDados(){
        System.out.println("Assunto:" + assunto.getAssunto() + "\n" +
                "Mensagem:" + "\n" + mensagem.getMensagem());
    }
}
