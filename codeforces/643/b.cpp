#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> e(n);
        for (int i=0;i<n;++i)
            scanf("%d", &e[i]);
        sort(e.begin(), e.end());

        int ans = 0;
        int gine = 0;
        int gsize = 0;
        bool newgroup = true;
        for (int i=0;i<n;++i) {
            if (newgroup) {
                newgroup = false;
                gsize = 0;
            }
            gine = e[i];
            gsize++;
            if (gsize >= gine) {
                newgroup = true;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}
