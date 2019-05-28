#include <bits/stdc++.h>
using namespace std;
int a[300000];
int main() {
    int n, k;
    int activated = 0;
    long long sum = 0;
    scanf("%d%d", &n, &k);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    sort(a, a+n);
    for (int i=0;i<k;++i) {
        sum += 1LL * activated * a[i];
        activated++;
    }
    for (int i=k;i<n;++i) {
        sum += 1LL * activated * a[i];
    }
    printf("%lld", sum);
}