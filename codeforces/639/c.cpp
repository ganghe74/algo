#include <bits/stdc++.h>
using namespace std;

int mod(int a, int p) {
    return (a % p + p) % p;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d", &n);
        set<int> s;
        for (int i=0;i<n;++i) {
            scanf("%d", &x);
            x = mod(i + mod(x, n), n);
            s.insert(x);
        }
        if (s.size() == n) puts("YES");
        else puts("NO");
    }
}
