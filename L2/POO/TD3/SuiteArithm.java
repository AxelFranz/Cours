public class SuiteArithm extends Suite{
	
	public SuiteArithm(int premier, int pas){
		super(premier,pas);
	}

	public int valeurAuRangN(int n){
		return (premier)+(n-1)*pas;
	}

	public int sommeAuRangN(int n){
		return (int)(n/2)*(premier+valeurAuRangN(n));
	}

	public int calculRang(int un){
		return (un-premier)/pas+1;
	}

}