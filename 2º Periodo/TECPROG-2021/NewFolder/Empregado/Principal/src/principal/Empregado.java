
package principal;
//Classe BASE
public class Empregado {
    protected String nome, cargo;
    protected int cpf;
    
    Empregado(String nome, String cargo, int cpf){
        this.nome = nome;
        this.cargo = cargo;
        this.cpf = cpf;         
    }
    public void mostraDados(){
        System.out.println("Nome: " + nome + ", CPF: " + cpf + ", Cargo: " + cargo);
    }
    public float calculaSalario(int horasTrab){
        return (float) 415.0;
    }
}   
