import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        BigInteger l = sc.nextBigInteger();
        BigInteger r = sc.nextBigInteger();
        BigInteger k = sc.nextBigInteger();
        BigInteger p = k;
        int c = 0;
        
        if( l.compareTo(BigInteger.ONE) == 0 ){
            c++;
            System.out.print("1 ");
        }
        
        
        while ( k.compareTo(r) <= 0 ) {
            if( k.compareTo(l) >=0 ){
                c++;
                System.out.print(k + " ");
            }
            k = k.multiply(p);
        }
        
        if( c==0 ){
            System.out.println("-1");
        }

    }

}
