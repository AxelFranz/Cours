class Perroquet extends Oiseau {
   protected boolean parle = false ;
   
   public Perroquet(String s) {
      super(s);
   }

   public void apprendParole() {
      parle = true ; 
   }

   public void dire() {
     if (parle)
        System.out.println(nom);
     else
        super.dire(); 
  }
} // Perroquet 

