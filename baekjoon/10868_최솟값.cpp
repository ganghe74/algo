#include <bits/stdc++.h>
using namespace std;

int a[100001], tree[400001];

void init(int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int query(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return -1;
    if (i <= start && end <= j) return tree[node];
    int m1 = query(node*2, start, (start+end)/2, i, j);
    int m2 = query(node*2+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    return min(m1, m2);
}

int main() {
    int N, M, s, e;
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) scanf("%d", &a[i]);
    init(1, 1, N);
    while (M--) {
        scanf("%d%d", &s, &e);
        printf("%d\n", query(1, 1, N, s, e));
    }
}