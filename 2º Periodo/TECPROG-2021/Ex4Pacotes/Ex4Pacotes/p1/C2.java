package p1;

public class C2
{
	private int a2;
	public int getA2() { return a2; }
	public void setA2(int n) { a2 = n; }
	
	public void acessar()
	{
		//Posso criar diretamente, pois a classe C1 faz
		//parte do mesmo pacote
		C1 obj = new C1();	
		obj.setA1(123);
		System.out.println(obj.getA1());
		
		
	}	
	
}