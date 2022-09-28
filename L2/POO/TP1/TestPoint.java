import java.util.Scanner;
public class TestPoint
{
	public static Point CreationPoint (int x,int y){
		if(x < 0)
		{
			System.out.println("Coordonnées de x invalides");
		} else if (y < 0)
		{
			System.out.println("Coordonnées de y invalides");
		}
		return new Point(x,y);
	}

	static public void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		
		Point p1 = CreationPoint(4,5);
		Point p2 = new Point(0,3);
		System.out.println(p1);
	}
}