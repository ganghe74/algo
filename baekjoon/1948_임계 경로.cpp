#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int>> a[10001], b[10001];
int ind[10001], d[10001];
int main() {
    int N, M, u, v, w, s, e, cnt=0;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d%d", &u, &v, &w);
        ind[v]++;
        a[u].push({v,w});
        b[v].push({u,w});
    }
    scanf("%d%d", &s, &e);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        while (!a[now].empty()) {
            int next = a[now].front().first;
            int cost = a[now].front().second;
            a[now].pop();
            d[next] = max(d[next], d[now]+cost);
            ind[next]--;
            if (!ind[next]) {
                q.push(next);
            }
        }
    }
    q.push(e);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        while (!b[now].empty()) {
            int next = b[now].front().first;
            int cost = b[now].front().second;
            b[now].pop();
            if (d[now]-cost == d[next]) {
                q.push(next);
                cnt++;
            }
        }
    }
    printf("%d\n%d", d[e], cnt);
}