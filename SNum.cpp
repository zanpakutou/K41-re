#include <bits/stdc++.h>

using namespace std;
int bt[100];
int res[100];
int dp[70][20][2][2];
long long n,k,d;
void  pt(int n)
{
       memset(bt,0,sizeof(bt));
       for(int i=0;i<=61;i++){
        bt[61-i]= n%2;
        n/=2;
       }
}
void bug()
{
    for(int i=55;i<=61;i++) cout<<res[i];
    cout<<'\n';
}
int calc(int i,int sD,bool mean,bool les)
{
       int &t= dp[i][sD][mean][les];
       if (t>-1) return t;
       if(i>61) {if (sD==k) t=1; else t=0;  return t;};
       t=0;
       int c=0;
       if (mean) c=1;
       res[i]=0;
       t+=calc(i+1,sD+ c,mean,les||bt[i]);
       if (bt[i]==1||les) {res[i]=1; t+=calc(i+1,sD,1,les);};
       return t;
}

int CH(int a)
{
       memset(dp,-1,sizeof(dp));
       n=a;
       pt(n);
       int x= calc(0,0,0,0);
       return x;
}

int main()
{

       long long  a,b;
       cin>>a>>b>>k;
       cout<<CH(b)-CH(a-1);
       return 0;
}
