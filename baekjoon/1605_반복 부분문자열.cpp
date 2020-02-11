#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint mod = 1e5+3;
int base = 256;

int main() {
    int L;
    char s[200001];
    scanf("%d %s", &L, s);
    int lo = 0, hi = L;
    while (lo+1 < hi) {
        int mid = (lo+hi) / 2;
        lint h = 0, first = 1;
        vector<int> pos[mod];
        bool found = false;
        for (int i=0;i<=L-mid;++i) {
            if (i == 0) {
                for (int j=0;j<mid;++j) {
                    h = (h * base + s[j]) % mod;
                    if (j > 0) first = (first * base) % mod;
                }
            }
            else h = (base * ((h - s[i-1] * first) % mod + mod) + s[i+mid-1]) % mod;
            if (!pos[h].empty()) {
                for (int p : pos[h]) {
                    bool same = true;
                    for (int j=0;j<mid;++j) {
                        if (s[i+j] != s[p+j]) {
                            same = false;
                            break;
                        }
                    }
                    if (same) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
            else pos[h].push_back(i);
        }
        (found ? lo : hi) = mid;
    }
    printf("%d\n", lo);
}
