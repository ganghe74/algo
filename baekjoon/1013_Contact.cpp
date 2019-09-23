#include <bits/stdc++.h>
using namespace std;

int T, N, d[200];
char s[201];

bool solve(int x) {
    if (x >= N) return true;
    if (d[x] != -1) return d[x];
    if (s[x] == '0') {
        if (s[x+1] == '1') return d[x] = solve(x+2);
        return d[x] = 0;
    }
    else {
        if (s[x+1] != '0' || s[x+2] != '0') return d[x] = false;
        int i = x;
        while (s[++i] == '0');
        if (s[i] != '1') return d[x] = false;
        while (s[i++] == '1') {
            if (solve(i)) return d[x] = true;
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(d, -1, sizeof(d));
        scanf("%s", s);
        N = strlen(s);
        if (solve(0)) puts("YES");
        else puts("NO");
    }
}