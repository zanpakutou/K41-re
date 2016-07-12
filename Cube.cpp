#include <bits/stdc++.h>
#define     M   111539786LL
using namespace std;
long long n, a,b,c;
long long sum(long long n)
{
    if (n==0) return 0;
    long long a1=n, a2=n+1, a3=2*n+1;
    if (a1%2) a2/=2; else a1/=2;
    if (a1%3==0) a1/=3;
    if (a2%3==0) a2/=3;
    if (a3%3==0) a3/=3;
    long long res=1;
    res=(a1*a2)%M;
    res=(res*a3)%M;
    res=(res*4)%M;
    res=(res+2*n+1)%M;
    return res;
}
int main()
{
    long long x;
    while(cin>>x) cout<<sum(x)<<'\n';
    return 0;
}
