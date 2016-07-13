#include <bits/stdc++.h>
#define      M      1000000007
using namespace std;

string s, b;
long long h1, h2;
int rl(char c)
{
    return (int)c-'a'+1;
}
long long pow(int a,int n)
{
    if (n==0) return 1;
    long long  tmp=pow(a,n/2);
    tmp=(tmp*tmp)%M;
    return (n%2)? (tmp*a%M): tmp;
}
int hash1(int i)
{
    int l= s.length()-i;
    h1=(h1+rl(s[l])*pow(26,i-1))%M;
    return h1;
}
int hash2(int i)
{
    h2=(h2*26+rl(s[i-1]))%M;
    return h2;
}
int main()
{
    cin>>s;
    int res=0;
    int l= s.length();
    for(int i=1;i<l;i++) if (hash1(i)==hash2(i)) res=max(res,i);
    res=l-res;
    cout<<res;
}
