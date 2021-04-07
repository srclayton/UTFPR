
package lista04email;

public class Assunto {
        private String texto;
    
    public boolean setAssunto(String texto){
        if(texto == null || texto.isEmpty())
            return false;
        else
            this.texto = texto;
        return true;
    }
    public String getAssunto(){
        if(texto == null || texto.isEmpty())
            return "";
        else
            return texto;        
    }
}
