#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i=0;i<n;++i) {
        scanf("%d", &a[i]);
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i=0;i<n;++i) {
        int x = a[i];
        auto upper = upper_bound(a.begin(), a.end(), 2*x);
        ans += upper - a.begin() - i - 1;
    }
    printf("%lld", ans);
}