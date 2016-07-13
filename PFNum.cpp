#include <bits/stdc++.h>

using namespace std;

long long dp[21][11][11][4][4];
long long a,b;
int dg[25]={0};
void pt(long long n)
{
    memset(dg,0,sizeof(dg));
    int c=0;
    while (n>0)
    {
        dg[19-c]=n%10;
        n/=10;
        c++;
    }
}
long long calc(int i,int lst1, int lst2, int mean,int les)
{
    long long &t= dp[i][lst1][lst2][mean][les];
    if (t>-1) return t;
    if (i>19) {
        if (les && mean>0) t=1; else t=0;
        return t;
    }
    t=0;
    for(int j=0;j<=9;j++)
    {
        if ((mean==1)&&(j!=lst2)) if(!les){
                if(j<=dg[i]) t+=calc(i+1,lst2,j,2,j<dg[i]);}
                    else t+=calc(i+1,lst2,j,2,les);
        if (mean==2) if (j!=lst1&&j!=lst2) if(!les)
           {
               if(j<=dg[i]) t+=calc(i+1,lst2,j,2,j<dg[i]);}
                    else t+=calc(i+1,lst2,j,2,les);
        if (mean==0)  if(!les){
            if(j<=dg[i]) t+=calc(i+1,lst2,j,(j>0)?1:0,j<dg[i]);}
                    else t+=calc(i+1,lst2,j,(j>0)?1:0,les);
    }
    return t;
}
long long calc(int x)
{
    pt(x);
    if (x<=0) return 0;
    memset(dp,-1,sizeof(dp));
    return calc(0,0,0,0,0);
}
int main()
{
    cin>>a>>b;
    cout<<calc(b+1)-calc(a);
    return 0;
}
