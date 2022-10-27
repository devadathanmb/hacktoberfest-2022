/*

import java.util.*;

class Palindrome{

public static void main(String args[]){

int len, flag=0;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the string");
String str=sc.nextLine();

len=str.length();

for(int i=0;i<=len/2;i++){
	if(str.charAt(i)!=str.charAt(len-i-1)){
		flag=1;
		break;}
}
if(flag==1)
	System.out.println("Not Palindrome");
else
	System.out.println("Palindrome");
}

}




*/

import java.util.*;
class Palindrome{

public static void main(String args[]){
int i=0, len;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the string");
String str=sc.nextLine();
String rev="";
len=str.length();
i=len-1;
while(i>=0){

rev= rev+str.charAt(i);
rev=rev.toLowerCase();
i--;}

System.out.println("Reversed String : "+rev);





}}

