import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BigInteger LCM(BigInteger a,BigInteger b){
        BigInteger c=a;
        c=c.multiply(b);
        BigInteger d=a.gcd(b);
        return c.divide(d);
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int ii=1;ii<=t;ii++){
            int n=sc.nextInt();
            BigInteger ans=new BigInteger("1");
            for(int i=0;i<n;i++){
                int a=sc.nextInt();
                BigInteger b=BigInteger.valueOf(a);
                ans=LCM(ans,b);
            }
            System.out.println("Case "+ii+": "+ans);
        }

    }
}
