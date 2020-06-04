#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i=0;i<n;++i) scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        bool f = false;
        for (int k=1;k<1024;++k) {
            auto b = a;
            for (int i=0;i<n;++i)
                b[i] ^= k;
            sort(b.begin(), b.end());
            if (a == b) {
                printf("%d\n", k);
                f = true;
                break;
            }
        }
        if (!f) puts("-1");
    }
}
