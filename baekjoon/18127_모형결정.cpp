#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    long long ans = 0;
    scanf("%d%d", &a, &b);
    for (int i=0;i<=b;++i) ans += (a-2) * (i+1) - (a-3);
    printf("%lld", ans);
}