#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 5;
    scanf("%d", &n);
    for (int i=2;i<=n;++i) ans = (ans + (i+1) * 3 - 2) % 45678;
    printf("%d", ans);
}