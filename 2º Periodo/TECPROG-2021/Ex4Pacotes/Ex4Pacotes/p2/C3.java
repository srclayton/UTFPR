package p2;

//declaramos que vamos utilizar a classe C1 do pacote p1
import p1.C1;
//idem para C2
import p1.C2;

//Pode ser import p1.*;

//Embora não esteja explícito no enunciado, a classe C3
//deve ser pública porque será utilizada pela classe de 
//entrada para fins de teste...
public class C3
{
	public void executar()
	{
		//Caso não se deseje utilizar um import, outra forma é:
		//p1.C1 obj1 = new p1.C1();
		
		C1 obj1 = new C1();	
		obj1.setA1(78);
		C2 obj2 = new C2();
		obj2.setA2(-90);
		
		System.out.println(obj1.getA1() + " " + obj2.getA2());
		
		
		//Ok criar este objeto aqui pois C4, embora não seja pública, faz parte do mesmo pacote de C3
		C4 obj4 = new C4();
		
	}
	
}

//Esta classe não é pública, portanto pode ser implementada em arquivo com qualquer nome.
class C4
{
	private int a4;
	public void setA4(int n) { a4 = n; }
	public int getA4() { return a4; }
	
}