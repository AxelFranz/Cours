public class ParcVoiture {
	private Voiture[] parc = new Voiture[3];
	public void tester(){
		parc[0] = new Voiture("lol", 5);
		parc[1] = new Voiture("lol", 6);
		parc[2] = new Voiture("lol",0);
		parc[0].demarrer();
		parc[0].arreter();
		parc[1].demarrer();
		parc[1].arreter();
		parc[2].demarrer();
		parc[2].fairePlein(20);
	}
	public ParcVoiture(){}

}