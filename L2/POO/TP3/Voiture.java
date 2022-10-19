public class Voiture {
	private String modele;
	Moteur m;

	public Voiture(String modele){
		this.modele=modele;
		m = new Moteur(0);
	}

	public Voiture(String modele, int init){
		m = new Moteur(init);
		this.modele=modele;
	}

	public Voiture(String modele, Moteur m){
		this.m = m;
		this.modele=modele;
	}

	public boolean demarrer(){
		return m.demarrer();
	}

	public void rouler(int cons){
		m.utiliser(cons);
		if(m.carburant == 0)
			System.out.println("Panne d'essence");
	}

	public void arreter(){
		System.out.println("Moteur arrête");
	}

	public void fairePlein(int a){
		m.fairePlein(a);
		System.out.println("Plein avec " + a + " litres");

	}

}