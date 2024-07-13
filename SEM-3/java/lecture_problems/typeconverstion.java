public class typeconverstion {
    static void main(String args[]) {
        byte b;
        int i = 55 ;
        double d = 3.142;

        System.out.println("Int 2 Byte ");
        b = (byte) i;
        System.out.println("after convertion i:" + i +",  b:"+ b);

        System.out.println("Double 2 Int ");
        i = (int) d;
        System.out.println("after convertion d:" + d +",  i:"+ i);    
        
        System.out.println("");
    }
}
