#include <bits/stdc++.h>

using namespace std;

long long dp[40][110];
int mn[100];
int res[100];
int n,m,k,lim;
void pre()
{
      cin>>n>>m>>k;
      if (n%2) lim=(n+1)/2; else lim=n/2;
      mn[0]=1;
      for(int i=1;i<=40;i++) mn[i]=(mn[i-1]*10)%m;
      memset(dp,-1,sizeof(dp));
}
long long calc(int i, int mod)
{
      long long &t= dp[i][mod];
      if (t>-1) return t;
      if (i>lim){
            if (mod==0)  t=1; else t=0;
            return t;
      }
      t=0;
      for(int j=(i==1)?1:0;j<=9;j++)
      {     ///cout<<j<<'\n';
           if (i<n/2) t+= calc(i+1,(mod+j*(mn[i-1]+mn[n-i]))%m); else
                  t+= calc(i+1,(mod+j*(mn[i]))%m);
      }
      return t;
}
void xuat()
{
      for(int i=1;i<=lim;i++) cout<<res[i];
      for(int i=lim+1;i<=n;i++) cout<<res[n-i+1];
}
void  mul(int i,int mod)
{
      if (i>lim&&mod==0){
            xuat();
            return;
      }
       for(int j=(i==1)?1:0;j<=9;j++)
      {
            long long  x;
            if (i<n/2) x= calc(i+1,(mod+j*(mn[i-1]+mn[n-i]))%m);
            else x= calc(i+1,(mod+j*(mn[i]))%m);
            if (k>x) k-=x; else {
                        res[i]=j;
                        if (i<n/2) mul(i+1,(mod+j*(mn[i-1]+mn[n-i]))%m);
                        else mul(i+1,(mod+j*(mn[i]))%m);
                        break;
            }
      }
}
int main()
{
     // freopen("Palinn.inp","r",stdin);
     // freopen("Palinn.out","w",stdout);
      pre();
      long long rs=0;
      rs+=calc(1,0);
      cout<<rs<<'\n';
      mul(1,0);
      return 0;
}
