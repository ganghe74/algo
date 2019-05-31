// upsolving
#include <bits/stdc++.h>
using namespace std;
long long d[90];
int main() {
    d[0] = 1; d[1] = 1;
    for (int i=2;i<90;++i) d[i] = d[i-1] + d[i-2];
    long long n, ans = 0;
    scanf("%lld", &n);
    while (n >= d[ans]) ans++;
    printf("%lld", ans-2);
}