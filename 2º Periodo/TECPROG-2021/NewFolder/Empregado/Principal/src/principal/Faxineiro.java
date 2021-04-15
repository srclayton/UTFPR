package principal;

public class Faxineiro extends Empregado{
    
    Faxineiro(String nome, int cpf){
        super(nome, "Faxineiro", cpf);
    }
    
    @Override
    public void mostraDados(){
        System.out.println("Nome do faxineiro: " + nome + "\n" +
                           "CPF: " + cpf + "\n");
    }
    @Override
    public float calculaSalario(int horasTrab){
        if(horasTrab <= 176)
            return (float) ((float) 176 * 4.5);
        
        int h=0;
        h = horasTrab - 176;
        return (float) ((float) 176 * 4.5) + ((float) h * 6);
    }
}
