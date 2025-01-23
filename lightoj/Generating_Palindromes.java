import java.util.*;
public class Main{
    static public final int N=105;
    static char[] s=new char[N];
    static int[][] dp=new int[N][N];
    static int find(int st,int en){
        if(st>=en){
            return 0;
        }
        if(dp[st][en]!=-1){
            return dp[st][en];
        }
        int ans=999999;
        if(s[st]==s[en]){
            ans=Math.min(ans,find(st+1,en-1));
        }else{
            ans=Math.min(ans,Math.min(1+find(st+1,en),1+find(st,en-1)));
        }
        dp[st][en]=ans;
        return dp[st][en];
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=1;i<=t;i++){
            for(int ii=0;ii<N;ii++){
                for(int jj=0;jj<N;jj++){
                    dp[ii][jj]=-1;
                }
            }
            s=sc.next().toCharArray();
            int ans=find(0,s.length-1);
            System.out.println("Case "+i+": "+ans);
        }
    }
}
