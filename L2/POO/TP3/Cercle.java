public class Cercle extends Point
{
	private double r;
	public Cercle (double x, double y, double r) {
		this.x = x;
		this.y=y;
		this.r = r;
	}

	public void deplaceCentre(double dx, double dy) {
		this.deplace(dx,dy);
	}

	public void changeRayon(double dr) {
		r += dr;
	}

	public Point getCentre() {
		return new Point(x,y);		
	}

	public String toString(){
		return "x = " + x + " , y = " + y;
	}
}