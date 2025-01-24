import java.math.BigInteger;
import java.util.*;
public class sol{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=1;i<=t;i++){
            String a=sc.next();
            String b=sc.next();
            BigInteger aa=new BigInteger(a);
            BigInteger bb=new BigInteger(b);
            if(aa.remainder(bb).compareTo(new BigInteger("0"))==0){
                System.out.println("Case "+i+": divisible");
            }
            else{
                System.out.println("Case "+i+": not divisible");
            }
        }
    }
}
