#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> a(N+1);
    iota(a.begin(), a.end(), 0);
    while (M--) {
        int b, e, m;
        scanf("%d%d%d", &b, &e, &m);
        vector<int> next(a);
        for (int i=m;i<=e;++i) next[i-m+b] = a[i];
        for (int i=b;i<m;++i) next[i+e-m+1] = a[i];
        a = next;
    }
    for (int i=1;i<=N;++i) printf("%d ", a[i]);
}