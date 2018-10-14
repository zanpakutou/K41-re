#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, cost;
    Edge(){};
    Edge(int U,int V,int __C) : u(U), v(V), cost(__C) {};
    int get(int x)
    {
        return x ^ u ^ v;
    }
};

const int MAXN  =   200 + 5;
typedef  pair< int, int >   ii;

Edge e[MAXN * MAXN];

int n, m, total, s, t, par[MAXN], dist[MAXN];
int flow[MAXN][MAXN], cap[MAXN][MAXN];
vector< int > a[MAXN];
long long total_cost = 0;

void READ()
{
    cin >> n >> m >> total >> s >> t ;
    int u, v, c, cost;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> cost >> c;
        e[i] = Edge(u, v, cost);
        cap[u][v] += c;
        cap[v][u] += c;
        a[u].push_back(i);
        a[v].push_back(i);
    }
}
bool Bellman()
{
    #define     dis         first
    #define     name        second
    vector< int >::iterator it;
    queue< ii > q;
    q.push( ii(0 , s) );
    memset(dist, 0x3c, sizeof(dist));
    dist[s] = 0;
    par[s]  = 0;
    while(!q.empty()){
        ii top = q.front(); q.pop();
        int u = top.name;
        int cost = top.dis;
        if ( dist[u]!=cost ) continue;
        for(it = a[u].begin(); it!= a[u].end(); it++){
            int v = e[*it].get(u);
            if(flow[u][v] >= cap[u][v]) continue;
            int n_cost = e[*it].cost + dist[u];
            if (dist[v] > n_cost){
                dist[v] = n_cost ;
                par[v]  =  u;
                q.push(ii(dist[v], v));
            }
        }
    }
    return (dist[t] < 0x3c3c3c3c);
}
void Plush()
{
    int __min = total;
    for(int u = t; int v = par[u]; u = v){
        __min = min(__min, flow[v][u] >= 0 ? cap[v][u] - flow[v][u] : -flow[v][u]);
    }
    for(int u = t; int v = par[u]; u = v){
            flow[v][u]+= __min;
            flow[u][v]-= __min;
    }
    total-= __min;
}
int main()
{
    READ();
    while(Bellman() && total) Plush();
    if (total){
        cout<< -1;
        return 0;
    }
    for(int u = 1; u <= n; u++)
        for(int j = 0; j < a[u].size(); j++){
            int i = a[u][j];
            int v = e[i].get( u );
            if (flow[u][v] > 0) total_cost+= 1LL * e[i].cost * flow[u][v];
        }
    cout<< total_cost << '\n';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if (flow[i][j] > 0) cout<< i << ' '<< j << ' ' << flow[i][j] << '\n';
        }
    cout<< 0 << ' ' << 0 << ' ' << 0 ;
}
/*
4 5 2000 1 4
1 4 1000000000 1000
1 3 999999999 1000
3 4 444444444 1000
1 2 222222222 1000
2 4 555555555 1000
*/
