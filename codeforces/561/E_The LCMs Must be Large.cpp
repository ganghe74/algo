// Wrong Answer

#include <bits/stdc++.h>
using namespace std;
bool lost[10001];
int main() {
    int m, n, si, idx;
    scanf("%d%d", &m, &n);
    while (m--) {
        vector<bool> c(n+1, 0);
        scanf("%d", &si);
        while (si--) {
            scanf("%d", &idx);
            c[idx] = 1;
        }
        for (int i=1;i<=n;++i) {
            if (!c[i]) lost[i] = 1;
        }
    }
    bool possible = false;
    for (int i=1;i<=n;++i) {
        if (!lost[i]) possible = true;
    }
    if (possible) puts("possible");
    else puts("impossible");
}