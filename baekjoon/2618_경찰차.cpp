#include <bits/stdc++.h>
using namespace std;

int N, W, r, c, d[1001][1001];
vector<pair<int,int>> a(1);
pair<int,int> path[1001][1001];

int dist(pair<int,int> p, pair<int,int> q) {
    return abs(p.first - q.first) + abs(p.second - q.second);
}

int solve(int i, int j) {
    if (i == j) return 0;
    if (d[i][j] != -1) return d[i][j];
    if (i-1 > j) {
        path[i][j] = {i-1, j};
        return d[i][j] = solve(i-1, j) + dist(a[i], a[i-1]);
    }
    if (i < j-1) {
        path[i][j] = {i, j-1};
        return d[i][j] = solve(i, j-1) + dist(a[j], a[j-1]);
    }
    if (i-1 == j) {
        path[i][j] = {0, j};
        d[i][j] = solve(0, j) + dist({1,1}, a[i]);
        for (int k=1;k<i-1;++k) {
            if (d[i][j] > solve(k, j) + dist(a[k], a[i])) {
                path[i][j] = {k, j};
                d[i][j] = solve(k, j) + dist(a[k], a[i]);
            }
        }
        return d[i][j];
    }
    if (i == j-1) {
        path[i][j] = {i, 0};
        d[i][j] = solve(i, 0) + dist({N,N}, a[j]);
        for (int k=1;k<j-1;++k) {
            if (d[i][j] > solve(i, k) + dist(a[k], a[j])) {
                path[i][j] = {i, k};
                d[i][j] = solve(i, k) + dist(a[k], a[j]);
            }
        }
        return d[i][j];
    }
    return d[i][j] = 1e9;
}

void trace(int x, int y) {
    if (!x && !y) return;
    trace(path[x][y].first, path[x][y].second);
    printf("%d\n", (x>y)?1:2);
}

int main() {
    scanf("%d%d", &N, &W);
    for (int i=0;i<W;++i) {
        scanf("%d%d", &r, &c);
        a.push_back({r, c});
    }
    memset(d, -1, sizeof(d));
    int x, y, cost=1e9;
    for (int i=0;i<W;++i) {
        if (solve(W, i) < cost) {
            x = W;
            y = i;
            cost = solve(W, i);
        }
        if (solve(i, W) < cost) {
            x = i;
            y = W;
            cost = solve(i, W);
        }
    }
    printf("%d\n", cost);
    trace(x, y);
}
