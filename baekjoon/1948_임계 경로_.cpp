#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> a(10001), b(10001);
int ind[10001], d[10001];
bool c[10001];
int main() {
    int N, M, u, v, w, s, e, cnt=0;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        ind[v]++;
        a[u].push_back({v,w});
        b[v].push_back({u,w});
    }
    scanf("%d%d", &s, &e);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (auto pi : a[now]) {
            int next = pi.first;
            int cost = pi.second;
            d[next] = max(d[next], d[now]+cost);
            if (--ind[next] == 0) {
                q.push(next);
            }
        }
    }
    a=b;
    q.push(e);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (auto pi : a[now]) {
            int next = pi.first;
            int cost = pi.second;
            if (d[now]-cost == d[next]) {
                cnt++;
                if (!c[next]) {
                    c[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    printf("%d\n%d", d[e], cnt);
}