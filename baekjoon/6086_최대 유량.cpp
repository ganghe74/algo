#include <bits/stdc++.h>
using namespace std;

int N, u, v, w, c[52][52], f[52][52];
vector<int> a[52];

int to_num(int u) {
    if (isupper(u)) return u - 'A';
    return u - 'a' + 26;
}

int main() {
    scanf("%d", &N);
    while (N--) {
        scanf(" %c %c%d", &u, &v, &w);
        u = to_num(u);
        v = to_num(v);
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v] = c[v][u] += w;
    }
    int total = 0, S = to_num('A'), T = to_num('Z');
    while (true) {
        vector<int> p(52, -1);
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
            flow = min(flow, c[p[i]][i]-f[p[i]][i]);
        for (int i=T;i!=S;i=p[i]) {
            f[p[i]][i] += flow;
            f[i][p[i]] -= flow;
        }
        total += flow;
    }
    printf("%d", total);
}
