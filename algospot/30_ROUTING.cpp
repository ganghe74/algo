#include <iostream>
#include <queue>
using namespace std;
int C, N, M;
vector<pair<int,double>> a[10000];

vector<double> dijkstra(int start) {
    vector<double> dist(N, 1e+300);
    dist[start] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push({-1, start});
    while (!pq.empty()) {
        double cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for (int i=0;i<a[now].size();++i) {
            int next = a[now][i].first;
            double nextDist = cost * a[now][i].second;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d", &C);
    while (C--) {
        for (int i=0;i<10000;++i) a[i].clear();
        scanf("%d%d", &N, &M);
        while (M--) {
            int u, v;
            double w;
            scanf("%d%d%lf", &u, &v, &w);
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        }
        vector<double> dist = dijkstra(0);
        printf("%.10lf\n", dist[N-1]);
    }
}