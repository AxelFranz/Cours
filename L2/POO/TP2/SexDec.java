public class SexDec {
	private int heure;
	private int mn;
	private int sec;

	public int getH() {
		return heure;
	}

	public int getM() {
		return mn;
	}

	public int getS() {
		return sec;
	}

	private void normaliser(){
		while(this.sec >= 60){
			this.sec-=60;
			this.mn++;
		}

		while(mn >= 60){
			this.mn-=60;
			this.heure++;
		}
	}

	public SexDec ajout(double duree)
	{
		int aled = (int) duree;
		this.heure+= aled;
		double vir = duree%1;
		this.mn += (vir * 60);
		this.normaliser();
		return this; 
	}

	public SexDec ajout(int h, int mn, int s) {
		this.heure+=h;
		this.mn+=mn;
		this.s+=s;
		this.normaliser();
		return this;
	}

	public String toString(){
		return ""+this.heure+" h "+this.mn+" mn "+this.sec+"s";
	}

	public SexDec (int heure, int mn, int sec) {
		this.heure=heure;
		this.mn=mn;
		this.sec=sec;
		this.normaliser();
	}
}