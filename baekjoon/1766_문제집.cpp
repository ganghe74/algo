#include <bits/stdc++.h>
using namespace std;
vector<int> a[32001];
int ind[32001];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        ind[v]++;
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i=1;i<=N;++i)
        if (!ind[i]) pq.push(i);
    while (!pq.empty()) {
        int now = pq.top(); pq.pop();
        printf("%d ", now);
        for (int next : a[now]) {
            --ind[next];
            if (!ind[next]) pq.push(next);
        }
    }
}