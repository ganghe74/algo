#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint base = 360000;
const lint mod = 1e9+7;

int n;
lint h1, h2;
vector<int> a, c1, c2;

bool matched(int idx) {
    for (int i=0;i<n;++i)
        if (c1[i] != c2[(idx+i)%n])
            return false;
    return true;
}

int main() {
    scanf("%d", &n);
    a.resize(n);

    for (int i=0;i<n;++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    c1.push_back(base - a.back() + a[0]);
    for (int i=1;i<n;++i)
        c1.push_back(a[i] - a[i-1]);

    for (int i=0;i<n;++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    c2.push_back(base - a.back() + a[0]);
    for (int i=1;i<n;++i)
        c2.push_back(a[i] - a[i-1]);

    for (int i=0;i<n;++i) {
        h1 = (h1 * base + c1[i]) % mod;
        h2 = (h2 * base + c2[i]) % mod;
    }

    lint first = 1;
    for (int i=1;i<n;++i)
        first = (first * base) % mod;

    for (int i=0;i<n;++i) {
        if (h1 == h2) {
            if (matched(i)) {
                puts("possible");
                return 0;
            }
        }
        h2 = h2 - (c2[i] * first) % mod;
        h2 = (h2 + mod) % mod;
        h2 = ((h2 * base) % mod + c2[i]) % mod;
    }
    puts("impossible");
}
