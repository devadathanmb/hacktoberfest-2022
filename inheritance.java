import java.util.*;

class Employee{

public void display(){
	System.out.println("Name of class is Employee");
}
public void calcSalary(){
	System.out.println("Salary of employee is 10000");
}
}

class Engineer extends Employee{

public void calcSalary(){
	System.out.println("Salary of employee is 30000");
}
}

class inheritance{
public static void main(String args[]){
Engineer e=new Engineer();
e.calcSalary();
e.display();
}
}