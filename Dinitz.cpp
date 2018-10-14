#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int) 1e3 + 10;
const int INF  = (int) 1e8;

int w, h, n, s, t, sum;
int cap[MAXN][MAXN], flow[MAXN][MAXN];
int q[MAXN], dist[MAXN], pr[MAXN];

bool BFS() {
    int l = 1;
    int r = 0;
    memset(dist, -1, sizeof dist);

    q[++r] = s; dist[s] = 0;
    while (l <= r) {
        int u = q[l++];
        for (int v = 0; v < n; ++v)
            if (flow[u][v] < cap[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q[++r] = v;
            }
    }

    return (dist[t] != -1);
}

int DFS(int u, int fl) {
    if (u == t) return fl;
    for (int &v = pr[u]; v < n; ++v) {
        if (flow[u][v] < cap[u][v] && dist[u] + 1 == dist[v]) {
            int d = DFS(v, min(cap[u][v] - flow[u][v], fl));
            if (d) {
                flow[u][v] += d;
                flow[v][u] -= d;
                return d;
            }
        }
    }
    return 0;
}

int Dinic(int v) {
    memset(flow, 0, sizeof flow);
    for (int i = 1; i <= h; ++i)
        cap[i + w][t] = v;

    int ans = 0;
    while (BFS()) {
        for (int i = 0; i < n; ++i) pr[i] = 0;
        while (1) {
            int d = DFS(s, INF);
            if (d) ans += d; else break;
        }
    }

    return ans;
}

int main() {
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d%d", &w, &h); n = w + h + 2; s = 0; t = n - 1;
    for (int i = 1; i <= w; ++i) {
        int p, x;
        scanf("%d%d", &cap[s][i], &p);
        sum += cap[s][i];
        while (p--) {
            scanf("%d", &x);
            cap[i][x + w] = cap[s][i];
        }
    }

    int l = 0;
    int r = INF;
    int f = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (Dinic(mid) == sum) {
            f = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    printf("%d", f);
    return 0;
}

