#include <bits/stdc++.h>
using namespace std;

int N, M, S, T, n, u, v, total, c[402][402], f[402][402];
vector<int> a[402];

int main() {
    S = 0; T = 401;
    scanf("%d%d", &N, &M);
    for (int v=1;v<=N;++v) {
        a[S].push_back(v);
        a[v].push_back(S);
        c[S][v]++;
    }
    for (int u=N+1;u<=N+M;++u) {
        a[u].push_back(T);
        a[T].push_back(u);
        c[u][T]++;
    }
    for (int u=1;u<=N;++u) {
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &v);
            v += N;
            a[u].push_back(v);
            a[v].push_back(u);
            c[u][v]++;
        }
    }
    while (true) {
        vector<int> p(402, -1);
        queue<int> q;
        q.push(S);
        while (!q.empty() && p[T] == -1) {
            int u = q.front(); q.pop();
            for (int v : a[u]) {
                if (p[v] == -1 && c[u][v] - f[u][v] > 0) {
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        if (p[T] == -1) break;
        int flow = 1e9;
        for (int i=T;i!=S;i=p[i])
            flow = min(flow, c[p[i]][i] - f[p[i]][i]);
        for (int i=T;i!=S;i=p[i]) {
            f[p[i]][i] += flow;
            f[i][p[i]] -= flow;
        }
        total += flow;
    }
    printf("%d", total);
}
