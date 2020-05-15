#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);

        vector<int> a(n);
        for (int i=0;i<n;++i) {
            scanf("%d", &a[i]);
            if (a[i] > k) a[i] = 2;
            else if (a[i] == k) a[i] = 1;
            else a[i] = 0;
        }

        bool hask = false, flag = (n == 1);
        for (int i=0;i<n;++i) {
            if (a[i] == 1) hask = true;
            for (int j=i+1;j<n&&j-i<=2;++j)
                if (a[i] && a[j]) flag = true;
        }

        if (hask && flag) puts("yes");
        else puts("no");
    }
}
