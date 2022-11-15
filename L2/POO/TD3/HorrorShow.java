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
	void destroy(){
		System.out.println("pan...");
	}	
	void menace(){
		System.out.println("brr...");
	}
} 

class Bat implements Vampire {
 ... 
} /* question 1 */

class HorrorShow
{
	static void u(Monster b) { ... } /* question 2 */
	static void v(DagerousMonster d) { ... } /* question 2 */
	public static void main(String[] args){	
	DragonZilla if2 = new DragonZilla();
... /* question 3 */
... /* question 4 */
	Bat bt1 = new Bat();
... /* question 5 */
	}
}