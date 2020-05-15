#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        int s = 0;
        for (int i=0;i<n;++i) {
            scanf("%1d", &a[i]);
            s += a[i];
        }
        int ans = s;
        for (int i=0;i<k;++i) {
            vector<int> b;
            for (int j=i;j<n;j+=k)
                b.push_back((a[j]==1)?-1:1);
            int cnt = 0;
            for (int x : b) {
                cnt = min(x, cnt+x);
                ans = min(ans, s+cnt);
            }
        }
        printf("%d\n", ans);
    }
}
