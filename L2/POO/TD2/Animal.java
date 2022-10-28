class Animal {
  protected String nom ; 
  protected int age = 0 ; 

  public Animal(String s) {
    nom = s ;
  }

  public void vieillir() {
    age ++ ;
  }

  public void dire() {
     System.out.println("...");
  }
} // Animal

