#include <bits/stdc++.h>
#define     ll      long long
using namespace std;
int  dp[20][300];

int res[30];

int n,p,k;

int  calc(int i,int sum)
{
     ///cout<<i<<' '<<sum<<'\n';
    int &t= dp[i][sum];
    if (t>-1) return t;
    t=0;
    if (i>=n){
    if (sum==k) t=1; else t=0; return t; };

    for(int j=0;j<=9;j++) t+=calc(i+1,sum+j);
    return t;
    cout<<n;
}
void xuat(){

    int i=0;
    while(res[i]==0 && i<n) i++;
    for(i=0;i<n;i++) cout<<res[i];
}
void built(int i,int sum)
{
    if (i>n&&sum==k){
        xuat();
        return ;
    }
    for(int j=0;j<=9;j++){
        int x= calc(i+1,sum+j);
        if (p>x) p-=x;
        else {
            res[i]=j;
            built(i+1,sum+j);
            break;
        }
    }
}
int main()
{
        cin>>n>>k>>p;
        memset(dp,-1,sizeof(dp));
        cout<<calc(0,0)<<'\n';
        built(0,0);
        return 0;
}
