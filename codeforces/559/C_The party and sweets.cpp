#include <bits/stdc++.h>
using namespace std;

int b[100000], g[100000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;++i) scanf("%d", &b[i]);
    for (int i=0;i<m;++i) scanf("%d", &g[i]);
    sort(b, b+n);
    sort(g, g+m);
    if (b[n-1] > g[0]) printf("-1");
    else {
        long long ans = 0;
        for (int i=0;i<n;++i) {
            ans += (long long)b[i] * m;
        }
        for (int i=1;i<m;++i) {
            ans += g[i] - b[n-1];
        }
        if (g[0] != b[n-1]) ans += g[0] - b[n-2];
        printf("%lld", ans);
    }
}

// 1 2 3 4 5
// 5 10 15 20 25 => 75

// 5 5 5 5 5 => 5 6 6 6 6 => 79
// 4 4 4 4 4 => 6 4 4 4 4 => 81

// 1 1 5
// 10 100

// 2 2 10 => 14

// 5 5 -> 5 100 -> 14 + 95 = 109
// 1 1 -> 10 1 -> 109 + 9 = 11


// 0 1
// 1 1 2

// 0 3 -> 3

// 1 1 1 -> 1 1 2 -> 0
// 0 0 0 -> 1 0 0 -> 0