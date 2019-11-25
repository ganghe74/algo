#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MOD = 1e9+7;

int N, M, K;
lint a[1000001], tree[4000001];

void init(int node, int start, int end) {
    if (start == end) tree[node] = a[start] % MOD;
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] * tree[node*2+1] % MOD;
    }
}

void update(int node, int start, int end, int i, int val) {
    if (i < start || i > end) return;
    if (start == end) {
        tree[node] = val;
        return;
    }
    update(node*2, start, (start+end)/2, i, val);
    update(node*2+1, (start+end)/2+1, end, i, val);
    tree[node] = tree[node*2] * tree[node*2+1] % MOD;
}

lint query(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return -1;
    if (i <= start && end <= j) return tree[node];
    lint m1 = query(node*2, start, (start+end)/2, i, j);
    lint m2 = query(node*2+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    return m1 * m2 % MOD;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=1;i<=N;++i) scanf("%lld", &a[i]);
    init(1, 1, N);
    M += K;
    while (M--) {
        int op, b, c;
        scanf("%d %d %d", &op, &b, &c);
        if (op == 1) update(1, 1, N, b, c);
        else printf("%lld\n", query(1, 1, N, b, c));
    }
}