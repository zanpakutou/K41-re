#include <bits/stdc++.h>

using namespace std;
int bt[100];
int dp[70][20][2][2];
int n,k,d;
bool get(int n,int i)
{
       return (n>>i)&1;
}
void  pt(int n)
{
       memset(bt,0,sizeof(bt));
       for(int i=0;i<=64;i++) bt[64-i]=get(n,i);
}
int calc(int i,int sD,bool mean,bool les)
{
       int &t= dp[i][sD][mean][les];
       if (t>-1) return t;
       if(i>64) { t=(sD==k)?1:0; return t;};
       t=0;
       t+=calc(i+1,sD+mean?1:0,mean,les||bt[i]); //cout<<0;
       if (bt[i]==1||les) {t+=calc(i+1,sD,1,les);};
       return t;
}
int CH(int a)
{
       memset(dp,-1,sizeof(dp));

       n=a;
       pt(n);
       //d=log2(n);
       //for(int i=0;i<=64;i++) cout<<bt[i];
       int x= calc(0,0,0,0);
       return x;
}
int main()
{

       int a,b,k;
       cin>>b>>k;
       cout<<CH(b);
       //pt(b);

       return 0;
}
