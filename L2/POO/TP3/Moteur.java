public class Moteur {
	int carburant;

	public Moteur(){
		carburant=0;
	}

	public Moteur(int carburant){
		this.carburant=carburant;
	}

	public boolean demarrer(){
		if(carburant>0){
			System.out.println("Moteur démarre avec " + carburant + " litres");
			carburant--;
			return true;
		} 
		System.out.println("Impossible de démarrer");
		return false;
	}

	public int utiliser(int cons) {
		int carbdeb = carburant;
		carburant-=cons;
		if(carburant<0){
			carburant = 0;
		}
		System.out.println("Moteur utilise " + (carbdeb-carburant) + " litres");
		return carburant;
	}

	public void arreter(){
		System.out.println("Moteur arrêté");
	}

	public void fairePlein(int a){
		carburant+=a;
	}
	

}