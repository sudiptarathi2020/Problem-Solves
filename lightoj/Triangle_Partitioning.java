
import java.util.*;
public class sol {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int test=sc.nextInt();
        for(int i=1;i<=test;i++){
            double a=sc.nextDouble();
            double b=sc.nextDouble();
            double c=sc.nextDouble();
            double d=sc.nextDouble();
            double p=Math.sqrt((d)/(d+1));
            System.out.println("Case "+i+": "+a*p);
        }
    }
}
