abstract class Shape{
	abstract void numberofsides();
}

class Rectangle extends Shape{
	void numberofsides(){
		System.out.println("The number of sides is 4");
	}
}

class Triangle extends Shape{
	void numberofsides(){
		System.out.println("The number of sides is 3");
	}
}

class Hexagon extends Shape{
	void numberofsides(){
		System.out.println("The number of sides is 6");
	}
}

class shapess{
	public static void main(String args[]){
	Rectangle r=new Rectangle();
	Triangle t=new Triangle();
	Hexagon h=new Hexagon();
	
	r.numberofsides();
	t.numberofsides();
	h.numberofsides();
	}
}