public abstract class Suite{
	 protected int premier;
	 protected int pas;

	public Suite(int premier, int pas){
		this.premier=premier;
		this.pas=pas;
	}

	abstract int valeurAuRangN(int n);

	abstract int sommeAuRangN(int n);
}