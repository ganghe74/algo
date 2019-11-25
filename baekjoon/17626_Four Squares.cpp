#include <bits/stdc++.h>
using namespace std;
int d[50001];
int solve(int n) {
    if (n <= 3) return n;
    if (d[n]) return d[n];
    d[n] = 100;
    for (int i=0;i*i<=n;++i) {
        d[n] = min(d[n], solve(n-i*i)+1);
    }
    return d[n];
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", solve(n));
}