class Capitale extends Ville{
	private String pays;
	public Capitale(String nom, String pays){
		super(nom);
		this.pays=pays;
	}

	public Capitale(String nom, String pays, int nbhab){
		super(nom,nbhab);
		this.pays=pays;
	}

	public String toString(){
		return this.nbHabconnus() ? "Nom : "+nom+"\nPays : "+pays+"\nNombre d'habitants : "+nbhab:"Nom : "+nom+"\nPays : "+pays+"\nNombre d'habitants inconnu"; 
	}

	public char categorie(){
		return 'C';
	}
}