
import java.util.*;
public class sol {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int test=sc.nextInt();
        for(int ii=1;ii<=test;ii++){
            double a=sc.nextDouble();
            int b=sc.nextInt();
            double theta=((double)360)/((double)2*b);
            theta=Math.toRadians(theta);
            double ans=a*Math.sin(theta)/(1+Math.sin(theta));
            System.out.println("Case "+ii+": "+ans);
        }
    }
}
