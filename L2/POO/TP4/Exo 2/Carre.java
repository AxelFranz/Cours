public class Carre
{
	
	protected double dx;
	
	public Carre(double c) {
		dx=c;
	}
	
	public double getCote(){
		return dx;
	}
	
	public void setCote(double c) {
		dx=c;
	}
	
	public double perimetre() {
		return 4*dx;
	}
	
	public double surface() {
		return dx*dx;
	}
	
	public String toString(){
		return "Je suis un carré" ;
	}
}