#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    if (n > m) puts("0");
    else {
        long long ans = 1;
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
                ans = (ans * abs(a[i] - a[j])) % m;
        printf("%lld", ans);
    }
}
