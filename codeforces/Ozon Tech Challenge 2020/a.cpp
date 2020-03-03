#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000], b[1000];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0;i<n;++i) scanf("%d", &a[i]);
        for (int i=0;i<n;++i) scanf("%d", &b[i]);
        sort(a, a+n);
        sort(b, b+n);
        for (int i=0;i<n;++i) printf("%d ", a[i]);
        puts("");
        for (int i=0;i<n;++i) printf("%d ", b[i]);
        puts("");
    }
}
