package ecomerce;

public class Item {
    private String nomeItem;
    private float valorUnit;
    private int qntd;
    
    Item(String nome, float valor, int qntd){
        nomeItem = nome;
        valorUnit = valor;
        this.qntd = qntd;
    }
    public String getNome(){
        return nomeItem;
    }
    public float getValorTotal(){
        return valorUnit*qntd;
    }
}
