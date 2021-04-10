package ecomerce;

public  class Principal {
    private static CarrinhoDeCompras carrinho = new CarrinhoDeCompras();
    
    public static void executar(){
        String  nome="roupa1";
        int qntd = 2;
        float valor = (float) 15.9;
        Item i = new Item(nome, valor, qntd);
        carrinho.adicionarItem(i);
        nome = "roupa2";
        qntd =1;
        valor = (float)1.5;
        Item ii = new Item(nome, valor, qntd);
        carrinho.adicionarItem(ii);
        System.out.println("valor:"+ carrinho.getValorTotal());
        carrinho.removerItem(i);
        System.out.println("valor:"+ carrinho.getValorTotal());
    }
    
    
}
