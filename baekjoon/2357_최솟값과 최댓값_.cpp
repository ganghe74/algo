#include <bits/stdc++.h>
using namespace std;

int a[100001], mintree[400001], maxtree[4000001];

void init(int node, int start, int end) {
    if (start == end) {
        mintree[node] = a[start];
        maxtree[node] = a[start];
    }
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        mintree[node] = min(mintree[node*2], mintree[node*2+1]);
        maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
    }
}

int minquery(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return -1;
    if (i <= start && end <= j) return mintree[node];
    int m1 = minquery(node*2, start, (start+end)/2, i, j);
    int m2 = minquery(node*2+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    return min(m1, m2);
}

int maxquery(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return -1;
    if (i <= start && end <= j) return maxtree[node];
    return max(maxquery(node*2, start, (start+end)/2, i, j), maxquery(node*2+1, (start+end)/2+1, end, i, j));
}

int main() {
    int N, M, s, e;
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) scanf("%d", &a[i]);
    init(1, 1, N);
    while (M--) {
        scanf("%d%d", &s, &e);
        printf("%d %d\n", minquery(1, 1, N, s, e), maxquery(1, 1, N, s, e));
    }
}