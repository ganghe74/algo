#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[100001];
int dist[100001];
int bfs(int x) {
    memset(dist, -1, sizeof(dist));
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (Edge e : a[now]) {
            if (dist[e.to] == -1) {
                q.push(e.to);
                dist[e.to] = dist[now] + e.cost;
            }
        }
    }
}
int main() {
    int V;
    scanf("%d", &V);
    for (int i=1;i<V;++i) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        a[x].push_back(Edge(y,d));
        a[y].push_back(Edge(x,d));
    }
    bfs(1);
    int start = 1;
    for (int i=1;i<=V;++i) {
        if (dist[i] > dist[start]) start = i;
    }
    bfs(start);
    int diameter = 0;
    for (int i=1;i<=V;++i) {
        if (dist[i] > diameter) diameter = dist[i];
    }
    printf("%d", diameter);
}