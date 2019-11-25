#include <bits/stdc++.h>
using namespace std;

int N, M, tree[400001];
bool lazy[400001];

void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        tree[node] = end - start + 1 - tree[node];
        if (start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int i, int j) {
    update_lazy(node, start, end);
    if (j < start || i > end) return;
    if (i <= start && end <= j) {
        tree[node] = end - start + 1 - tree[node];
        if (start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, i, j);
    update_range(node*2+1, (start+end)/2+1, end, i, j);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int i, int j) {
    update_lazy(node, start, end);
    if (j < start || i > end) return 0;
    if (i <= start && end <= j) return tree[node];
    return query(node*2, start, (start+end)/2, i, j) + query(node*2+1, (start+end)/2+1, end, i, j);
}

int main() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int o, s, t;
        scanf("%d%d%d", &o, &s, &t);
        if (!o) update_range(1, 1, N, s, t);
        else printf("%d\n", query(1, 1, N, s, t));
    }
}