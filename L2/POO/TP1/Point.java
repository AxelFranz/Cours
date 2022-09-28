class Point
{
	private int x ;
	private int y ;
	private static int totalPoint = 0;
	private int numeroOrdre;
	public Point(int x, int y, String nomA)
	{
		this.x=x;
		this.y=y;
		totalPoint++;
		this.numeroOrdre = totalPoint;
		final String nom = nomA;
	}

	public Point()
	{
		x = 10;
		y = 30;
		totalPoint++;
	}

	public int getX(){
		return this.x;
	}

	public int getY()
	{
		return this.y;
	}

	public static boolean egalite (Point p1, Point p2) {
		if (p1 == null || p2 == null){
			return false;
		}
		return (p1.x==p2.x && p1.y==p2.y);
	}
	public boolean egalite(Point p){
		if (this == null || p == null){
			return false;
		}
		return (this.x==p.x && this.y==p.y);
	}

	public boolean egalASoi()
	{
		return this.x==this.x&&this.y==this.y;
	}

	public String toString ()
	{
		return "Point numero "+this.numeroOrdre+" sur "+this.totalPoint+" : "+"abscisse : " + this.x + ", ordonnee : " + this.y ;
	}
}