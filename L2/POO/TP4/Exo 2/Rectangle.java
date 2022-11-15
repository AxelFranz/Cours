public class Rectangle extends Carre
{
	protected double dy;
	
	public Rectangle(double dx, double dy){
		super(dx);
		this.dy=dy;
	}
	
	public double getdx(){
		return this.getCote();
	}
	
	public double getdy(){
		return dy;
	}
	
	public void setdx(double dx) {
		this.setCote(dx);
	}
	
	public void setdy(double dy){
		this.dy=dy;
	}
	
	public double perimetre(){
		return 2*dx+2*dy;
	}

	public double surface(){
		return dx*dy;
	}

	public String toString(){
		return "Je suis un rectangle";
	}
}