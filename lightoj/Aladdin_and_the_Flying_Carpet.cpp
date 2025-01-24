
#include<bits/stdc++.h>
using namespace std;
const long long sz=1e6+100;
vector<long long>v;
void sieve()
{
    bool arr[sz+10];
    memset(arr,true,sizeof(arr));
    arr[0]=arr[1]=false;
    for(long long i=2;i*i<=sz;i++)
    {
        if(arr[i])
        {
            for(long long j=i*i;j<=sz;j+=i)
            {
                arr[j]=false;
            }
        }
    }
    for(long long i=2;i<=sz;i++)
    {
        if(arr[i])
        {
			v.push_back(i);	
		}
    }
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    sieve();
    long long test;
    cin>>test;
    for(long long t=1;t<=test;t++)
    {
        long long ans=1;
        long long a,b,temp;
        cin>>a>>b;
        temp=a;
        long long rt=sqrt(a);
        if(b*b==a or rt<b)
        {
            cout<<"Case "<<t<<": "<<"0\n";
            continue;
        }
        int len=(long long)v.size();
        for(long long i=0;i<len and v[i]*v[i]<=a;i++)
        {
            long long cnt=0;
            if(a%v[i]==0)
            {
                while(a%v[i]==0)
                {
                    cnt++;
                    a/=v[i];
                }
            }
            ans*=(cnt+1);
        }
        if(a!=1)
        {
            ans<<=1;
        }
        ans>>=1;
        for(long long i=1;i<b;i++)
        {
            if(temp%i==0)
            {
                ans--;
            }
        }
        cout<<"Case "<<t<<": "<<ans<<'\n';
    }
    return 0;
}
