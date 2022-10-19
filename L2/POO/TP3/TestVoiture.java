public class TestVoiture{
	public static void main (String[] args){
		Voiture v = new Voiture("Seat IBIZA",40);
		v.demarrer();
		v.rouler(10);
		v.rouler(10);
		v.rouler(10);
		v.rouler(10);
		v.fairePlein(50);
		v.rouler(10);
		v.arreter();

		ParcVoiture p1 = new ParcVoiture();
		p1.tester();
	}
}