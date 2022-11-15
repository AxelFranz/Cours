public class Carre extends Rectangle{
// dx=dy
	public Carre(double c) {
		super(c,c);
	}

	public double getCote() {
		return this.getdx();
	} 

	public void setCote(double c) {
		this.setdx(c);
		this.setdy(c);
	} 

	public String toString(){
		return "Je suis un carre";
	}
}