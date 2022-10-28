public class Ville{
	
	protected final String nom;
	protected int nbhab=0;

	public Ville(String nom){
		this.nom=nom;
	}

	public Ville(String nom, int nbhab){
		this.nom=nom;
		this.nbhab=nbhab;
	}

	public void printTARACE(){
		System.out.println(nom);
	}

}