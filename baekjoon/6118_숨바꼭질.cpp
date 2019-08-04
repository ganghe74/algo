#include <bits/stdc++.h>
using namespace std;

vector<int> a[20001];
int d[20001];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : a[now]) {
            if (!d[next]) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }
    int idx = 1;
    for (int i=1;i<=N;++i) {
        if (d[i] > d[idx]) idx = i;
    }
    for (int i=1;i<=N;++i) {
        if (d[i] == d[idx]) M++;
    }
    printf("%d %d %d", idx, d[idx]-1, M+1);
}