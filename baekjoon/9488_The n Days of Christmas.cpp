#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
int main() {
    for (int i=1;i<=1000000;++i) a[i] = a[i-1] + 1LL * i * (i+1) / 2;
    while (true) {
        int n, ans = 0;
        scanf("%d", &n);
        if (n == 0) break;
        printf("%lld\n", a[n]);
    }
}