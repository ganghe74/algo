#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint a, b, ans = 1;
    scanf("%lld%lld", &a, &b);
    for (lint i=a;i<=b;++i) ans = (ans * (i*(i+1)/2 % 14579) ) % 14579;
    printf("%lld", ans);
}