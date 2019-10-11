#include <bits/stdc++.h>
using namespace std;
vector<int> a[10001];
int main() {
    int N, M, u, v, com[10001];
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        a[v].push_back(u);
    }
    for (int i=1;i<=N;++i) {
        vector<bool> c(10001);
        int cnt = 0;
        queue<int> q;
        q.push(i);
        c[i] = 1;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int next : a[now]) {
                if (!c[next]) {
                    c[next] = 1;
                    q.push(next);
                    cnt++;
                }
            }
        }
        com[i] = cnt;
        M = max(M, cnt);
    }
    for (int i=1;i<=N;++i)
        if (com[i] == M) printf("%d ", i);
}