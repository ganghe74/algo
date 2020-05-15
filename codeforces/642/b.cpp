#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n), b(n);
        for (int i=0;i<n;++i) scanf("%d", &a[i]);
        for (int i=0;i<n;++i) scanf("%d", &b[i]);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i=0;i<n;++i) {
            if (b[n-i-1] > a[i] && k > 0) {
                swap(b[n-i-1], a[i]);
                k--;
            }
        }
        int s = 0;
        for (int i=0;i<n;++i) s += a[i];
        printf("%d\n", s);
    }
}
