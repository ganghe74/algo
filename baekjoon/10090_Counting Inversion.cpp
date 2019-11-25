#include <bits/stdc++.h>
using namespace std;

int N, x, tree[4000001];
long long ans;

void update(int node, int start, int end, int i, int diff) {
    if (i < start || i > end) return;
    tree[node] += diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, i, diff);
        update(node*2+1, (start+end)/2+1, end, i, diff);
    }
}

int query(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return 0;
    if (i <= start && end <= j) return tree[node];
    return query(node*2, start, (start+end)/2, i, j) + query(node*2+1, (start+end)/2+1, end, i, j);
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        update(1, 1, N, x, 1);
        ans += query(1, 1, N, x+1, N);
    }
    printf("%lld", ans);
}