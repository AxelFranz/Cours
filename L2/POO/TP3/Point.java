class Point 
{
  double x, y ; 

  public Point(double x, double y) 
  {
     this.x = x ; 
     this.y = y;
  }
  
  public void deplace(double dx, double dy) 
  {
     x += dx ; 
     y += dy ; 
  }
  
  public String toString() 
  {
     return "Point de coordonnees : " + x + ", " + y ; 
  }
} 
