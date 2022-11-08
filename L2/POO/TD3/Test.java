public class Test{
	public static void main(String[] args){
		SuiteArithm s1 = new SuiteArithm(5,5);
		SuiteGeom s2 = new SuiteGeom(5,5);
		System.out.println(s1.sommeAuRangN(2));
		System.out.println(s1.valeurAuRangN(2));
		System.out.println(s2.sommeAuRangN(2));
		System.out.println(s2.valeurAuRangN(2));
		System.out.println(s1.calculRang(10));
	}
}