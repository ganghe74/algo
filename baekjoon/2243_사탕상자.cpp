#include <bits/stdc++.h>
using namespace std;

int t[4000000];

void update(int node, int s, int e, int p, int diff) {
    if (p < s || e < p) return;
    t[node] = t[node] + diff;
    if (s != e) {
        update(node*2, s, (s+e)/2, p, diff);
        update(node*2+1, (s+e)/2+1, e, p, diff);
    }
}

int query(int node, int s, int e, int k) {
    if (s == e) return s;
    if (k <= t[node*2]) return query(node*2, s, (s+e)/2, k);
    return query(node*2+1, (s+e)/2+1, e, k-t[node*2]);
}

int main() {
    int n, a, b, c;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            b = query(1, 0, 1000000, b);
            update(1, 0, 1000000, b, -1);
            printf("%d\n", b);
        }
        else {
            scanf("%d%d", &b, &c);
            update(1, 0, 1000000, b, c);
        }
    }
}
