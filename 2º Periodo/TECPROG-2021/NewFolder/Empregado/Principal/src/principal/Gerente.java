package principal;

public class Gerente extends Empregado {
    int bonus;
    
    Gerente(String nome, int cpf, int bonus){
        super(nome, "Gerente", cpf);
        this.bonus = bonus;
    }
    @Override
    public void mostraDados(){
        System.out.println("Nome do Gerente: " + nome + "\n" +
                           "CPF: " + cpf + "\n" +
                           "Bonus: " + bonus );
    }
    
    @Override
    public float calculaSalario(int horasTrab){
        if(horasTrab <= 176)
            return (float) ((float) (176 * 30.0) + bonus );
        else
            return (float) ((float)176 * 30.0 );
    }
}
