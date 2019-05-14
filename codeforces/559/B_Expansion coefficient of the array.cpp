#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ai, k = 1e+9;
    scanf("%d", &n);    
    for (int i=1;i<=n;++i) {
        scanf("%d", &ai);
        int ij = max(i-1, n-i);
        k = min(k, ai / ij);
    }
    printf("%d", k);
}

