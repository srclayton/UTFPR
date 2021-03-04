import p1.C1;
import p2.C3;
import p2.C4;

public class Ex4Pacotes
{
	//método main
	public static void main (String [] args)
	{
		C1 obj1 = new C1();		
		C3 obj3 = new C3();
		
		//Erro! A classe C4 não pode ser acessada de fora
		//do pacote p2, pois não é pública!
		//C4 obj4 = new C4();
		
		obj3.executar();
		obj1.setA1(234);
		System.out.println(obj1.getA1());
		
		
		
	}	
	
}