class GarbageCollect{
	public void finalize(){
		System.out.println("Garbage collected");
	}
	public static void main(String args[]){
		GarbageCollect g1=new GarbageCollect();
		GarbageCollect g2=new GarbageCollect();
		g1=null;
		g2=null;
		System.gc();
	}



}