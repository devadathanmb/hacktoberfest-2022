class kbitflip {
    public static int minKBitFlips(int[] nums, int k) {
        int flips = 0,start = 0;
        try{
        do{
            start = find1stzero(nums);
            if(start == -1)
                return 0;
            if(start+k > nums.length-1)
                start = nums.length-k;
            nums = flip(nums, start, k);
            flips++;
            if (flips>nums.length)
                return -1;
        }while(!checkallone(nums));}
        catch(Exception e){
            System.out.println(e);
            return -1;
        }
        return flips;
    }
    public static boolean checkallone(int[] array){
        for(int i=0;i<array.length;i++){
            if(array[i]==0)
                return false;
        }
        return true;
    }

    public static int find1stzero(int[] array){
        for(int i=0;i<array.length;i++){
            if(array[i]==0)
                return i;
        }
        return -1; 
    }

    public static int[] flip(int[] array, int start, int k){
        for(;k!=0;k--){
            array[start]=(array[start]==0)?1:0;
            start++;
        }
        return array;
    }


//  printarray(nums);
    public static void printarray(int[] array){
        System.out.print("[");
        for(int i=0;i<array.length;i++){
            System.out.print(array[i]);
            String ch = (i==array.length-1)?"":", ";
            System.out.print(ch);
        }    
        System.out.print("]");
        System.out.println("");
    }

    public static void main(String args[]){
        int[] nums = {0,0,0,1,0,1,1,0};
        int k = 3;
        int ans = minKBitFlips(nums, k);
        System.out.println(ans);
    }
}


