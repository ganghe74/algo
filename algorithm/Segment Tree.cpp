// https://www.acmicpc.net/problem/10999
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N, M, K, a[1000001], tree[4000001], lazy[4000001];

void init(int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int i, int j, lint diff) {
    update_lazy(node, start, end);
    if (i > end || j < start) return;
    if (i <= start && end <= j) {
        tree[node] += (end-start+1) * diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, i, j, diff);
    update_range(node*2+1, (start+end)/2+1, end, i, j, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

lint query(int node, int start, int end, int i, int j) {
    update_lazy(node, start, end);
    if (i > end || j < start) return 0;
    if (i <= start && end <= j) return tree[node];
    return query(node*2, start, (start+end)/2, i, j) + query(node*2+1, (start+end)/2+1, end, i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i=1;i<=N;++i) cin >> a[i];
    init(1, 1, N);
    M += K;
    while (M--) {
        lint op, b, c, d;
        cin >> op >> b >> c;
        if (op == 1) {
            cin >> d;
            update_range(1, 1, N, b, c, d);
        }
        else {
            cout << query(1, 1, N, b, c) << endl;
        }
    }
}