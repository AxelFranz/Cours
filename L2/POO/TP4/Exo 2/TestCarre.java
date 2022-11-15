public class TestCarre {
	public static void main (String[] args)
	{
		Carre[] tableau; 
		tableau = new Carre[5]; 
		tableau[0]=(Rectangle) new Rectangle(5,2.25);
		tableau[1]= new Carre(10);
		tableau[2]=	new Carre(8.5);
		tableau[3]=(Rectangle) new Rectangle(2.5,6);
		tableau[4]=(Rectangle) new Rectangle(3.3,7.1);
		for (int i=0; i<5 ; i++){
			if(String(tableau[i])=="Je suis un carre")
			System.out.println(tableau[i]+". J'ai pour abscisse et ordonnée : "+tableau[i].getdx()+ ", "+tableau[i].getdy()); 
			System.out.println("Mon périmètre et ma surface sont respectivements "+tableau[i].perimetre()+ ", "+tableau[i].surface()+"\n");
		}
	}
}