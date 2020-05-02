#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        vector<bool> c(n+1);
        for (int i=0;i<n;++i) {
            scanf("%d", &a[i]);
            c[a[i]] = 1;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        if (a.size() > k) puts("-1");
        else {
            int i = 1;
            while (a.size() < k) {
                if (!c[i]) a.push_back(i);
                i++;
            }
            printf("%d\n", n * (int)a.size());
            while (n--)
                for (int x : a) printf("%d ", x);
            puts("");
        }
    }
}
