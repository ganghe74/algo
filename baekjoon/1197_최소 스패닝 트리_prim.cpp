#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a[10001];
bool c[10001];
int main() {
    int V, E, u, v, w, s=0;
    scanf("%d%d", &V, &E);
    while (E--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    priority_queue<pair<int,int>> pq;
    for (auto pi : a[1]) pq.push({-pi.second, pi.first});
    c[1]=1;
    while (!pq.empty()) {
        w = -pq.top().first;
        v = pq.top().second;
        pq.pop();
        if (c[v]) continue;
        c[v]=1;
        for (auto pi : a[v]) pq.push({-pi.second, pi.first});
        s += w;
    }
    printf("%d", s);
}