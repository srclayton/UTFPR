package ecomerce;

public class CarrinhoDeCompras {
    private Item [] item = new Item[5];
    private int count=0;
    
    public boolean adicionarItem(Item i){
        if(i == null)
            return false;
        else
            item[count] = i;
        count++;
        return true;
    }
    public boolean removerItem(Item i){
        if(i != null){
            for(int j = 0; j < count; j++){ // percorro o array verificando se o item informado esta dentro do array, 
                if(i == item[j]){//            caso esteja, jogo todos os dados a direita para esquerda, afim de liberar a ultima posição
                    for(int k =j; k < count; k++)// para poder deixa-la vaga para inserir um novo item;
                        item[k] = item[k+1];
                    item[count] = null;
                }
                    
            }
            count--;
            return true;
        }
        else 
            return false;
    }
    float getValorTotal(){
        float valor=0;
        for(int i=0; i<count;i++)
            valor = valor + item[i].getValorTotal();
        return valor;
    }
}
