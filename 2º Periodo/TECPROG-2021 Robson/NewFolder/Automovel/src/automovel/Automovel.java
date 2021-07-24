package automovel;

class Carro{
    private float consumo;
    private float capacidadeMaxima;
    private float nivelCombustivel;

    
    Carro(float consumo, float capacidade){
        this.consumo = consumo;
        capacidadeMaxima = capacidade;
        nivelCombustivel = 0;
    }
    
    public void andar(float percurso){
        nivelCombustivel -= percurso / consumo;
    }
    public float getCombustivel(){
        return nivelCombustivel;
    }
    public boolean abastecer(float abastece){
        if(abastece + nivelCombustivel > 0 && abastece + nivelCombustivel <= capacidadeMaxima){
            nivelCombustivel += abastece;
            return true;
        }else
            return false;
    }
    
}
class Iniciar{
    private static float sobra;
    
    public static void executar(){
        Carro gol = new Carro(12, 45); // 12 quilômetros por litro de combustível, capacidade do tanque é 45 litros
        if(gol.abastecer(20) == true)
            System.out.println("Veiculo abastecido com 20L.");
        else
            System.out.println("Não foi possivel abastecer o veiculo!");
        Carro uno = new Carro(14,40);
        if(uno.abastecer(25) == true)
            System.out.println("Veiculo abastecido com 25L.");
        else
            System.out.println("Não foi possivel abastecer o veiculo!");
        uno.andar(150);
        sobra = uno.getCombustivel();
        System.out.println("Listros restantes no Uno: "+ sobra);
        gol.andar(80);
        sobra = gol.getCombustivel();
        System.out.println("Litros restantes no Gol: "+sobra);

    }
}

public class Automovel {
    public static void main(String[] args) {
        Iniciar.executar();
}
    
}
