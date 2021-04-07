
package lista04email;

public class Mensagem {
    private String txtMensagem;
    
    public boolean addMensagem(String texto){
        if(texto == null || texto.isEmpty())
            return false;
        else
            txtMensagem = texto;
        return true;
    }
    public String getMensagem(){
        if(txtMensagem == null || txtMensagem.isEmpty())
            return "";
        else
            return txtMensagem;
    }
}
