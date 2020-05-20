#include <bits/stdc++.h>
using namespace std;

int N, P, u, v, c[400][400], f[400][400];
vector<int> a[400];

int main() {
    scanf("%d%d", &N, &P);
    while (P--) {
        scanf("%d%d", &u, &v);
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v]++;
    }
    int total = 0, S = 0, T = 1;
    while (true) {
        vector<int> p(N, -1);
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
