#include <iostream>
#include <queue>
using namespace std;
const int INF = 1e+9;
int C, V, E, n, m;
int main() {
    scanf("%d", &C);
    while (C--) { 
        vector<pair<int,int>> a[1001];
        scanf("%d%d%d%d", &V, &E, &n, &m);
        while (E--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            a[u].push_back({v, w});
            a[v].push_back({u, w});
        }
        vector<int> dist(V+1, INF);
        priority_queue<pair<int,int>> pq;
        vector<int> fire(n);
        for (int i=0;i<n;++i) scanf("%d", &fire[i]);
        for (int i=0;i<m;++i) {
            int start;
            scanf("%d", &start);
            pq.push({0, start});
            dist[start] = 0;
        }
        while (!pq.empty()) {
            int now = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            for (int i=0;i<a[now].size();++i) {
                int next = a[now][i].first;
                int nextDist = cost + a[now][i].second;
                if (nextDist < dist[next]) {
                    dist[next] = nextDist;
                    pq.push({-nextDist, next});
                }
            }
        }
        int ans = 0;
        for (int x : fire) ans += dist[x];
        printf("%d\n", ans);
    }
}