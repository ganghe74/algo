#include <bits/stdc++.h>
using namespace std;
vector<int> a[1001];
int ind[1001], d[1001];
int main() {
    int N, M, u, v;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        ind[v]++;
    }
    queue<int> q;
    for (int i=1;i<=N;++i)
        if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : a[now]) {
            if (--ind[next] == 0) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }
    for (int i=1;i<=N;++i) printf("%d ", d[i]+1);
}