#include <bits/stdc++.h>
using namespace std;

int n, m, op, i, j, a[100001];
pair<int,int> t[400000];

void build(int n, int s, int e) {
    if (s == e) t[n] = {a[s], s};
    else {
        build(n*2, s, (s+e)/2);
        build(n*2+1, (s+e)/2+1, e);
        t[n] = min(t[n*2], t[n*2+1]);
    }
}

void update(int n, int s, int e, int i, int v) {
    if (i < s || e < i) return;
    if (s == e) t[n] = {v, s};
    else {
        update(n*2, s, (s+e)/2, i, v);
        update(n*2+1, (s+e)/2+1, e, i, v);
        t[n] = min(t[n*2], t[n*2+1]);
    }
}

pair<int,int> query(int n, int s, int e, int i, int j) {
    if (j < s || i > e) return {2e9, 0};
    if (i <= s && e <= j) return t[n];
    return min(query(n*2, s, (s+e)/2, i, j), query(n*2+1, (s+e)/2+1, e, i, j));
}

int main() {
    a[0] = 2e9;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", a+i+1);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%d", &op, &i, &j);
        if (op == 1) update(1, 1, n, i, j);
        else printf("%d\n", query(1, 1, n, i, j).second);
    }
}
