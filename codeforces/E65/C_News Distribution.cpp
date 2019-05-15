#include <bits/stdc++.h>
using namespace std;

set<int> a[500001];
int ans[500001];
bool c[500001];

void bfs(int start) {
    int cnt = 0;
    queue<int> q, q2;
    q.push(start); q2.push(start);
    c[start] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for (int next : a[now]) {
            if (!c[next]) {
                q.push(next); q2.push(next);
                c[next] = 1;
            }
        }
    }
    
    while (!q2.empty()) {
        int now = q2.front();
        q2.pop();
        ans[now] = cnt;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0;i<m;++i) {
        int k;
        scanf("%d", &k);
        vector<int> group(k);
        for (int j=0;j<k;++j) scanf("%d", &group[j]);
        for (int ii=0;ii<k-1;++ii) {
            a[group[ii]].insert(group[ii+1]);
            a[group[ii+1]].insert(group[ii]);
        }
    }
    for (int i=1;i<=n;++i) {
        if (!c[i]) bfs(i);
    }
    for (int i=1;i<=n;++i) printf("%d ", ans[i]);
}