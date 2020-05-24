#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i=0;i<n;++i)
            scanf("%d", &a[i]);
        int ans = 1e9;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (i == j) continue;
                ans = min(ans, abs(a[i]-a[j]));
            }
        }
        printf("%d\n", ans);
    }
}
