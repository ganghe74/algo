#include <bits/stdc++.h>
using namespace std;
vector<int> a[501];
bool c[501];
int main() {
    int n, m, x, y, cnt = 0;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<pair<int,int>> q;
    q.push({1,2});
    c[1] = 1;
    while(!q.empty()) {
        int now = q.front().first;
        int k = q.front().second;
        q.pop();
        if (k == 0) continue;
        for (int next : a[now]) {
            if (!c[next]) {
                q.push({next, k-1});
                c[next] = 1;
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}