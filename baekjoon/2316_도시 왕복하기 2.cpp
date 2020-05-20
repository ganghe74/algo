#include <bits/stdc++.h>
using namespace std;

int N, P, u, v, c[800][800], f[800][800];
vector<int> a[800];

int main() {
    scanf("%d%d", &N, &P);
    for (int i=0;i<N;++i) {
        a[i*2].push_back(i*2+1);
        a[i*2+1].push_back(i*2);
        c[i*2][i*2+1]++;
    }
    while (P--) {
        scanf("%d%d", &u, &v);
        a[u*2-1].push_back(v*2-2);
        a[v*2-2].push_back(u*2-1);
        c[u*2-1][v*2-2]++;
        a[v*2-1].push_back(u*2-2);
        a[u*2-2].push_back(v*2-1);
        c[v*2-1][u*2-2]++;
    }
    int total = 0, S = 1, T = 2;
    while (true) {
        vector<int> p(N*2, -1);
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
