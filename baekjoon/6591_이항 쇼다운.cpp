#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    r = min(r, n-r);
    long long ret = 1;
    for (int i=1;i<=r;++i) {
        ret *= n--;
        ret /= i;
    }
    return ret;
}

int main() {
    int n, k;
    while (true) {
        scanf("%d%d", &n, &k);
        if (n == 0 && k == 0) break;
        printf("%d\n", nCr(n, k));
    }
}