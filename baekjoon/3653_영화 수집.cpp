#include <bits/stdc++.h>
using namespace std;

int tc, n, m, x, t[400001], pos[100001];
int b = 200000;

void update(int p, int val) {
    for (t[p+=b]=val;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {
    int ret = 0;
    for (l+=b,r+=b;l<r;l>>=1,r>>=1) {
        if (l&1) ret += t[l++];
        if (r&1) ret += t[--r];
    }
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        memset(t, 0, sizeof(t));
        scanf("%d%d", &n, &m);
        for (int i=n;i>0;--i) {
            pos[i] = n-i;
            update(i-1, 1);
        }
        for (int i=0;i<m;++i) {
            scanf("%d", &x);
            printf("%d ", query(pos[x]+1, b));
            update(pos[x], 0);
            pos[x] = n+i;
            update(pos[x], 1);
        }
        puts("");
    }
}
