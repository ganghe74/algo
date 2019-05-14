#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        vector<long long> a(n);
        for (long long i=0;i<n;++i) scanf("%lld", &a[i]);
        sort(a.begin(), a.end());

        bool possible = true;
        long long ans = a[0] * a[n-1];
        long long l = 0, r = n-1;
        while (l <= r) {
            if (a[l] * a[r] != ans) {
                possible = false;
            }
            l++; r--;
        }

        vector<long long> mydiv;
        long long i = 2;
        for (;i*i<ans;++i) {
            if (ans % i == 0) {
                mydiv.push_back(i);
                mydiv.push_back(ans/i);
            }
        }
        if (i*i == ans) mydiv.push_back(i);
        sort(mydiv.begin(), mydiv.end());

        if (mydiv.size() != a.size()) possible = false;
        else {
            for (long long i=0;i<n;++i) {
                if (mydiv[i] != a[i]) possible = false;
            }
        }

        if (possible) printf("%lld\n", ans);
        else puts("-1");
    }
}