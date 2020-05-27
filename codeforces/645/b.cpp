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
        a.push_back(0);
        sort(a.begin(), a.end());

        int ans = 1;
        for (int i=1;i<=n;++i) {
            if (a[i] <= i) ans++;
            else {
                int cnt=1;
                while (i+1 <= n && a[i] > i) {
                    i++;
                    cnt++;
                }
                if (a[i] <= i) ans += cnt;
            }
        }
        printf("%d\n", ans);
    }
}
