#include <bits/stdc++.h>
using namespace std;
vector<int> a[1001];
int ind[1001];
int main() {
    int N, M, t, u, v;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d", &t, &u);
        while (--t) {
            scanf("%d", &v);
            ind[v]++;
            a[u].push_back(v);
            u = v;
        }
    }
    queue<int> q, ans;
    for (int i=1;i<=N;++i) {
        if (!ind[i]) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front(); q.pop();
        ans.push(now);
        for (int next : a[now]) {
            --ind[next];
            if (ind[next] == 0) {
                q.push(next);
            }
        }
    }
    if (ans.size() != N) puts("0");
    else {
        while (!ans.empty()) {
            printf("%d\n", ans.front()); ans.pop();
        }
    }
}