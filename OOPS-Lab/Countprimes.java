import java.util.*;
class Countprimes {
    
    public static ArrayList<Boolean> list = new ArrayList<>();

    public int fn (int n) {
        if(n>1)
            fillarray(list, n);
        int count = n-1;
        if(n>1){
            for(int j=2;(j*j)<=n;j++){
                for(int k=2*j;k<=n;k+=j){
                    if(list.get(k)==true){
                        list.set(k,false);
                        count--;
                    }
                }
            }
            if(list.get(n)==true)
                count--;
        }
        else{
            count = 0;
        }
        return count;
    }


    public static ArrayList<Boolean> fillarray(ArrayList<Boolean> list, int n){
        list.add(0,false);
        list.add(1,false);
        for(int i=2;i!=n+1;i++)
            list.add(i,true);
        return list;
    }

    public static void main(String args[]){
        System.out.print("Enter number n: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Countprimes cp = new Countprimes();
        int count = cp.fn(n);
        System.out.println("The number of primes are: "+count);
    }
}