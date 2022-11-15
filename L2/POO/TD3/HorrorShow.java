interface Monster{
	void menace();
}

interface DangerousMonster extends Monster{
	void destroy();
}

interface Vampire{
	void drinkBlood();
}
class DragonZilla implements DangerousMonster {
	public void destroy(){
		System.out.println("pan...");
	}

	public void menace(){
		System.out.println("brr...");
	}
}


class Bat implements Vampire {
	public void drinkBlood(){
		System.out.println("slurp...");
	}
}

class HorrorShow
{
	static void u(Monster b) {return;} /* question 2 */
	static void v(DangerousMonster d) {return;} /* question 2 */
	public static void main(String[] args){	
	DragonZilla if2 = new DragonZilla();
    u(if2);
    v(if2);
	Bat bt1 = new Bat();
    bt1.drinkBlood();
	}
}