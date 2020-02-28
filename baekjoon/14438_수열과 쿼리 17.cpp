#include <bits/stdc++.h>
using namespace std;

int N, M, q, x, y, a[100000], tree[400000];

void init(int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int query(int node, int start, int end, int i, int j) {
    if (i > end || j < start) return -1;
    if (i <= start && end <= j) return tree[node];
    int m1 = query(node*2, start, (start+end)/2, i, j);
    int m2 = query(node*2+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    return min(m1, m2);
}

void update(int node, int start, int end, int i, int v) {
    if (i < start || end < i) return;
    if (start == end) {
        tree[node] = v;
        return;
    }
    update(node*2, start, (start+end)/2, i, v);
    update(node*2+1, (start+end)/2+1, end, i, v);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    init(1, 0, N-1);
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d%d", &q, &x, &y);
        if (q == 1) update(1, 0, N-1, x-1, y);
        else printf("%d\n", query(1, 0, N-1, x-1, y-1));
    }
}
