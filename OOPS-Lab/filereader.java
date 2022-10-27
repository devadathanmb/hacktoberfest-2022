import java.io.*;
class filereader{

public static void main(String args[]){

try{
FileReader fr=new FileReader("aa.txt");
FileWriter fw=new FileWriter("bb.txt");
BufferedReader br= new BufferedReader(fr);

String str=br.readLine();
fw.write(str);
System.out.println(str);

fr.close();
fw.close();

}
catch(IOException e)
{
System.out.println(e.getMessage());
}



}


}
