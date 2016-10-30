import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n,m;
        BigInteger x=BigInteger.ZERO,y=BigInteger.ZERO,k;
     
        int p,d,bx,by;
        
        n = sc.nextInt();
        bx = sc.nextInt();

        p = n-1;

        for(int i=0; i<n; i++){
            d = sc.nextInt();
            if( bx==10 ){
                x = x.multiply(BigInteger.TEN);
                x = x.add(BigInteger.valueOf(d));
            }else{
                k = BigInteger.valueOf(bx).pow(p);
                k = k.multiply(BigInteger.valueOf(d));
                x = x.add(k);
                p--;
            }
        }

        m = sc.nextInt();
        by = sc.nextInt();

        p = m-1;

        for(int i=0; i<m; i++){
            d = sc.nextInt();
            if( by==10 ){
                y = y.multiply(BigInteger.TEN);
                y = y.add(BigInteger.valueOf(d));
            }else{
                k = BigInteger.valueOf(by).pow(p);
                k = k.multiply(BigInteger.valueOf(d));
                y = y.add(k);
                p--;
            }
        }
        
        p = x.compareTo(y);
        if( p==0) System.out.println("=");
        else if( p<0 ) System.out.println("<");
        else System.out.println(">");


    }

}
