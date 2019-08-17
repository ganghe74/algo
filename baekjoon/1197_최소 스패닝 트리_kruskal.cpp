#include <bits/stdc++.h>
using namespace std;

int p[10001];

int Find(int x) {
    if (p[x] == x) return x;
    return p[x] = Find(p[x]);
}

int Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x] = y;
}

int main() {
    iota(p, p+10001, 0);
    int V, E, u, v, w, s = 0;
    scanf("%d%d", &V, &E);
    priority_queue<tuple<int,int,int>> pq;
    while (E--) {
        scanf("%d%d%d", &u, &v, &w);
        pq.push({-w,u,v});
    }
    while (!pq.empty()) {
        tie(w, u, v) = pq.top(); pq.pop();
        if (Find(u) == Find(v)) continue;
        Union(u, v);
        s -= w;
    }
    printf("%d", s);
}