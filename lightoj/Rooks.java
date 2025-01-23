import java.util.*;
public class M{
	public static Long gcd(Long a, Long b)
	{
	    if (b==(long)0) return a;
	    return gcd(b,a%b);
	}
	public static void main(String[] args){
		Scanner inp=new Scanner(System.in);
		int tt=inp.nextInt();
		int mx=31;
		Long arr[][]=new Long[mx][mx];
		Long fact[]=new Long[mx];
		fact[0]=fact[1]=1L;
		for(int i=2;i<31;i++)
		{
			fact[i]=fact[i-1]*((long)i);
		}
		
		for(int i=0;i<31;i++)
		{
			for(int j=0;j<31;j++)
			{
				arr[i][j]=0L;
			}
		}
		arr[0][0]=1L;
		for(int i=1;i<31;i++)
		{
			arr[i][0]=arr[i][i]=1L;
			for(int k=1;k<31;k++)
			{
				arr[i][k]=arr[i-1][k-1]+arr[i-1][k];
				//System.out.println(i+":"+k+":"+arr[i][k]);
			}
		}
		for(int iiii=1;iiii<=tt;iiii++)
		{
			int a,b;
			a=inp.nextInt();b=inp.nextInt();
			if(b>a)
			{
				System.out.println("Case "+iiii+": 0");
			}
			else if(a==b)
			{
				Long t=(long)1;
				while(a>0)
				{
					t*=a;
					a--;
				}
				System.out.println("Case "+iiii+": "+t);
			}
			else
			{
				Long ans=(long)0;
				ans=arr[a][b]*arr[a][b]*fact[b];
				System.out.println("Case "+iiii+": "+ans);
			}
		}
	}
}
