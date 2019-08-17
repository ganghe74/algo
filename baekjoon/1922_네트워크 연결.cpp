#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a[1001];
bool c[1001];
int main() {
    int N, M, u, v, w, s=0;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    priority_queue<pair<int,int>> pq;
    for (auto pi : a[1]) pq.push({-pi.second, pi.first});
    c[1] = 1;
    while (!pq.empty()) {
        w = -pq.top().first;
        v = pq.top().second;
        pq.pop();
        if (c[v]) continue;
        for (auto pi : a[v]) pq.push({-pi.second, pi.first});
        s += w;
        c[v] = 1;
    }
    printf("%d", s);
}