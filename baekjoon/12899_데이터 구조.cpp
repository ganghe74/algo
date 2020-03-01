#include <bits/stdc++.h>
using namespace std;

int N, T, X, t[8000000], a[2000000];

void init(int node, int start, int end) {
    if (start == end) t[node] = a[start];
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        t[node] = t[node*2] + t[node*2+1];
    }
}

void update(int node, int start, int end, int i, int diff) {
    if (i < start || end < i) return;
    t[node] += diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, i, diff);
        update(node*2+1, (start+end)/2+1, end, i, diff);
    }
}

int query(int node, int start, int end, int k) {
    if (start == end) return start;
    if (k <= t[node*2]) return query(node*2, start, (start+end)/2, k);
    return query(node*2+1, (start+end)/2+1, end, k-t[node*2]);
}

int main() {
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &T, &X);
        if (T == 1) {
            update(1, 1, 2000000, X, 1);
        }
        else {
            X = query(1, 1, 2000000, X);
            update(1, 1, 2000000, X, -1);
            printf("%d\n", X);
        }
    }
}
