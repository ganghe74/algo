#include <bits/stdc++.h>
using namespace std;

int n;
double x[102], y[102], d[102];

int main() {
    scanf("%lf%lf", x, y);
    scanf("%lf%lf", x+1, y+1);
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%lf%lf", x+i+2, y+i+2);
    fill(d+1, d+n+2, INFINITY);
    priority_queue<pair<double,int>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        for (int v=0;v<n+2;++v) {
            if (u == v) continue;
            double cost, l = hypot(x[u]-x[v], y[u]-y[v]);
            if (u <= 1 || l < 30.0) cost = l / 5.0;
            else cost = abs(l-50) / 5.0 + 2.0;
            double nextDist = -dist + cost;
            if (nextDist < d[v]) {
                d[v] = nextDist;
                pq.push({-nextDist, v});
            }
        }
    }
    printf("%lf", d[1]);
}
