public class Ville{
	
	protected final String nom;
	protected int nbhab=0;

	public Ville(String nom){
		this.nom=nom.toUpperCase();
	}

	public Ville(String nom, int nbhab){
		this.nom=nom.toUpperCase();
		this.nbhab=nbhab;
	}

	public String getNom(){
		return nom;
	}

	public int getNbhab(){
		return nbhab;
	}

	public void setNbhab(int a){
		this.nbhab=a;
	}

	public boolean nbHabconnus(){
		return this.nbhab>0 ? true : false;
	}

	public String toString(){
		return this.nbHabconnus() ? "Nom : "+nom+"\nNombre d'habitants : "+nbhab : "Nom : "+nom+"\nNombre d'habitants inconnu"; 
	}

	public char categorie(){
		if(nbhab==0) return '?';
		if(nbhab<500000) return 'A';
		return 'B';
	}

}