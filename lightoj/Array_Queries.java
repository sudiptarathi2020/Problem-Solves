
import java.util.*;
public class sol {
    static int[] segtree;
    public sol(int[] arr,int n){
        int newsize=4*n;
        segtree=new int[newsize];

        cons(arr,0,n-1,0);
    }
    public int cons(int[] arr,int st,int en,int pos){
        if(st==en){
            segtree[pos]=arr[st];
            return segtree[pos];
        }
        int mid=(st+en)/2;

        segtree[pos]=Math.min(cons(arr,st,mid,2*pos+1),cons(arr,mid+1,en,2*pos+2));
        return segtree[pos];
    }
    public int getmin(int ss, int se, int qs, int qe,int pos){
        if (qs <= ss && qe >= se)
            return segtree[pos];
        if (se < qs || ss > qe)
            return 100005;
        int mid=(ss+se)/2;
        return Math.min(getmin(ss,mid,qs,qe,2*pos+1),getmin(mid+1,se,qs,qe,2*pos+2));
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=1;i<=t;i++){
            int n=sc.nextInt();
            int tt=sc.nextInt();
            int[] arr=new int[n];
            for(int ii=0;ii<n;ii++){
                arr[ii]=sc.nextInt();
            }
            sol seg=new sol(arr,n);
            System.out.println("Case "+i+": ");
            while(tt>0){
                tt--;
                int a=sc.nextInt();
                int b=sc.nextInt();
                System.out.println(seg.getmin(0,n-1,a-1,b-1,0));
            }
        }
    }
}
