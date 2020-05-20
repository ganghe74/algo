#include <bits/stdc++.h>
using namespace std;

int n, m, d[11][1<<10];

char a[11][11];

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;++i)
        scanf(" %s", a[i]);
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    for (int i=1;i<=n;++i) {
        for (int pstate=0; pstate<(1<<m); ++pstate) {
            if (d[i-1][pstate] == -1) continue;
            for (int state=0; state<(1<<m); ++state) {
                int cnt = 0;
                int last = -5;
                for (int k=0; k<m; ++k) {
                    if (a[i][k] == '#') continue;
                    if (state & (1<<k)) {
                        if (i-1 == 0 || !(pstate & (1<<k)) || a[i-1][k] == '#') cnt++;
                    }
                    else {
                        if (last+1 != k) cnt++;
                        last = k;
                    }
                }
                if (d[i][state] == -1 || d[i][state] > d[i-1][pstate] + cnt)
                    d[i][state] = d[i-1][pstate] + cnt;
            }
        }
    }
    int ans = INT32_MAX;
    for (int state=0; state<(1<<m); ++state)
        ans = min(ans, d[n][state]);
    printf("%d", ans);
}
