import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        BigInteger two = BigInteger.valueOf(2);
        BigInteger n = sc.nextBigInteger();
        BigInteger t = n.subtract(BigInteger.ONE);
        if( n.mod(two).compareTo(BigInteger.ZERO) == 0 ){
            BigInteger tem = n;
            n = t;
            t = tem;
        }
        BigInteger N = n.subtract(BigInteger.ONE).divide(two);
        N = N.add(BigInteger.ONE);
        BigInteger odd = N.multiply( n.add(BigInteger.ONE) );
        odd = odd.divide(two);
        N = t.subtract( two ).divide(two);
        N = N.add(BigInteger.ONE);
        BigInteger even = N.multiply( t.add(two) ).divide(two);
        System.out.println( even.subtract(odd));
    }
    

}
