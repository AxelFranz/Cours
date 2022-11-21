// FRANZ Axel

interface CollisionSolarSystem{
	public double collision(Planet namePlanetCollision);
}

class SolarSystem{
	protected String nameSolar;

	public SolarSystem(String nameSolar){
		this.nameSolar=nameSolar;
	}

	public String getNameSolar(){
		return nameSolar;
	}
}

class Planet extends SolarSystem{
	protected String namePlanet;
	protected int distanceFromSolar;

	public Planet(String nameSolar, String namePlanet, int distanceFromSolar){
		super(nameSolar);
		this.namePlanet=namePlanet;
		this.distanceFromSolar=distanceFromSolar;
	}

	public int getDistanceFromPlanet(Planet secPlanet){
		return Math.abs(((Planet)this).getDistanceFromSolar() - ((Planet)secPlanet).getDistanceFromSolar());
	}

	public String getNamePlanet(){
		return namePlanet;
	}

	public int getDistanceFromSolar(){
		return distanceFromSolar;
	}

	public String toString(){
		return "Notre système solaire a pour étoile le " + nameSolar + " et pour planète "+ namePlanet + " à une distance de " + distanceFromSolar + " millions de km";
	}
}

class Asteroid extends Planet implements CollisionSolarSystem{
	protected int vitesseAsteroid;

	public Asteroid(String nameSolar, String namePlanet, int distanceFromSolar, int vitesseAsteroid){
		super(nameSolar, namePlanet, distanceFromSolar);
		this.vitesseAsteroid=vitesseAsteroid;
	}

	public double collision(Planet namePlanetCollision){
		long vitesse = vitesseAsteroid;
		return (((Planet)this).getDistanceFromPlanet(namePlanetCollision)*1000000/(double)vitesse)*24*365;
	}

	public String toString(){
		return "Asteroide " + namePlanet;
	}
}

public class TestSolarSystem{
	public static void main(String[] args){
		final int NB_OBJECT_PLANET = 4;
		SolarSystem[] objectPlanet = new SolarSystem[NB_OBJECT_PLANET];
		objectPlanet[0] = new Planet("Soleil", "Mercure", 58);
		objectPlanet[1] = new Planet("Soleil","Vénus",108);
		objectPlanet[2] = new Planet("Soleil","Terre",150);	
		objectPlanet[3] = new Planet("Soleil","Mars",228);

		// Etape 1
		for(int i = 0; i < objectPlanet.length;i++) System.out.println(objectPlanet[i]+" à une distance de "+((Planet)objectPlanet[i]).getDistanceFromSolar()+" millions de km");
		System.out.println();

		// Etape 2
		for(int i = 0; i < objectPlanet.length;i++){
			for(int j = i+1; j  < objectPlanet.length;j++){
				int DistancePlanetPlanet = ((Planet)objectPlanet[i]).getDistanceFromPlanet((Planet)objectPlanet[j]);
				System.out.println("La distance entre "+ ((Planet)objectPlanet[i]).getNamePlanet() + " et " + ((Planet)objectPlanet[j]).getNamePlanet()+ " est égale à " + DistancePlanetPlanet +" millions de km");
			}
		}
		System.out.println();

		// Etape 3
		final int NB_OBJECT_ASTEROID = 1;
		SolarSystem[] objectAsteroid = new SolarSystem[NB_OBJECT_ASTEROID];
		objectAsteroid[0]=new Asteroid("Soleil", "Destructor", 510, 10000);
		System.out.println(objectAsteroid[0]+ " à "+ ((Planet)objectAsteroid[0]).getDistanceFromSolar() + " millions de km avec risque de collion avec "+ ((Planet)objectPlanet[2]).getNamePlanet() + " dans "+ ((Asteroid)objectAsteroid[0]).collision((Planet)objectPlanet[2]) + " ans");
	}
}
