#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &tree, int node, int start, int end, int i, int diff) {
    if (i < start || i > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, diff);
        update(tree, node*2+1, (start+end)/2+1, end, i, diff);
    }
}
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        return start;
    } else {
        if (k <= tree[node*2]) {
            return kth(tree, node*2, start, (start+end)/2, k);
        } else {
            return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
        }
    }
}

int main() {
    int n, q, x;
    scanf("%d%d", &n, &q);
    vector<int> t(4*n);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &x);
        update(t, 1, 1, n, x, 1);
    }

    int sz = n;
    while (q--) {
        scanf("%d", &x);
        if (x > 0) {
            update(t, 1, 1, n, x, 1);
            sz++;
        }
        else {
            x = -x;
            int k = kth(t, 1, 1, n, x);
            update(t, 1, 1, n, k, -1);
            sz--;
        }
    }

    if (sz == 0) puts("0");
    else printf("%d", kth(t, 1, 1, n, 1));
}
