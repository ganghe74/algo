#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint N, M, K, a[1000001], tree[4000001];

void init(int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

lint query(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return -1;
    if (i <= start && end <= j) return tree[node];
    lint m1 = query(node*2, start, (start+end)/2, i, j);
    lint m2 = query(node*2+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    return m1 + m2;
}

void update(int node, int start, int end, int i, lint diff) {
    if (i < start || i > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, i, diff);
        update(node*2+1, (start+end)/2+1, end, i, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i=1;i<=N;++i) cin >> a[i];
    init(1, 1, N);
    M += K;
    while (M--) {
        lint op, b, c;
        cin >> op >> b >> c;
        if (op == 1) {
            update(1, 1, N, b, c-a[b]);
            a[b] = c;
        }
        else {
            cout << query(1, 1, N, b, c) << endl;
        }
    }
}