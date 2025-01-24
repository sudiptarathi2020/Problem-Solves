#include<stdio.h>
#include<algorithm>
#define ll long long
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll c=std::__gcd(a,b);
        c=(a*b)/c;
        printf("%lld %lld\n",c/a,c/b);
    }
    return 0;
}
