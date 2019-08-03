#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[10000];
    long long sum = 0;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) sum += abs(a[i]-a[j]);
    }
    printf("%lld", sum);
}