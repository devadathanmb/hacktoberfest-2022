class Countingbits {
    public int[] countBits(int n) {
        int[] a = new int[n+1];
        for(int i=0;i<=n;i++){
            a[i] = count1(i);
        }
        return a;    
    }
    public static int count1(int n){
        int num=0;
        for(;n>0;n=n>>1){
            num = ((n&1)==0)?num:num+1;
        }
        return num;
    }

    public static void main(String args[]){
        Countingbits fn = new Countingbits();
        int[] a = fn.countBits(5);
        System.out.print("[");
        for(int i=0;i<a.length;i++){
            System.out.print(a[i]);
            String ch = (i==a.length-1)?"":", ";
            System.out.print(ch);
        }    
        System.out.print("]");    
    }
}