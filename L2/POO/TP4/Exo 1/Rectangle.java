public class Rectangle{
	
	protected double dx;
	
	protected double dy;
	
	public Rectangle(double dx, double dy) {
		this.dx=dx;
		this.dy=dy;
	}
	
	public double getdx() {
		return dx;
	} 
	
	public double getdy() {
		return dy;
	}
	
	public void setdx(double dx){
		this.dx=dx;
	} 
	
	public void setdy(double dy){
		this.dy=dy;
	} 
	
	public double perimetre(){
		return 2*dx+2*dy;
	}	
	
	public double surface() {
		return dx*dy;
	}
	
	public String toString()
	{
	return "Je suis un rectangle. " ;
	}

}