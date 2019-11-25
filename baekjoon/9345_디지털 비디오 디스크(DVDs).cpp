#include <bits/stdc++.h>
using namespace std;

int T, N, K, a[100000], maxtree[400000], mintree[400000];

void init(int node, int start, int end) {
    if (start == end) {
        maxtree[node] = a[start];
        mintree[node] = a[start];
    }
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
        mintree[node] = min(mintree[node*2], mintree[node*2+1]);
    }
}

void update(int node, int start, int end, int i, int val) {
    if (i < start || i > end) return;
    if (start == end) {
        maxtree[node] = val;
        mintree[node] = val;
    }
    else {
        update(node*2, start, (start+end)/2, i, val);
        update(node*2+1, (start+end)/2+1, end, i, val);
        maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
        mintree[node] = min(mintree[node*2], mintree[node*2+1]);
    }
}

int maxquery(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return -1;
    if (i <= start && end <= j) return maxtree[node];
    return max(maxquery(node*2, start, (start+end)/2, i, j), maxquery(node*2+1, (start+end)/2+1, end, i, j));
}

int minquery(int node, int start, int end, int i, int j) {
    if (j < start || i > end) return 1e9;
    if (i <= start && end <= j) return mintree[node];
    return min(minquery(node*2, start, (start+end)/2, i, j), minquery(node*2+1, (start+end)/2+1, end, i, j));
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        iota(a, a+N, 0);
        init(1, 0, N-1);
        while (K--) {
            int Q, A, B;
            scanf("%d%d%d", &Q, &A, &B);
            if (Q == 0) {
                swap(a[A], a[B]);
                update(1, 0, N-1, A, a[A]);
                update(1, 0, N-1, B, a[B]);
            }
            else {
                if (maxquery(1, 0, N-1, A, B) == B && minquery(1, 0, N-1, A, B) == A) puts("YES");
                else puts("NO");
            }
        }
    }
}