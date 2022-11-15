public class SuiteGeom extends Suite{

	public SuiteGeom(int premier, int pas){
		super(premier,pas);
	}

	public int valeurAuRangN(int n){
		return premier*(int)Math.pow(pas,n-1);
	}

	public int sommeAuRangN(int n){
		return premier*(1-(int)Math.pow(pas,n))/(1-pas);
	}

	public int calculRang(int un){
		return ((int)Math.log(un/premier)/(int)Math.log(pas))+1;
	}
	
}