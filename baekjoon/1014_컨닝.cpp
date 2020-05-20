#include <bits/stdc++.h>
using namespace std;

int tc, n, m, d[10][1<<10];
char a[10][11];

bool isset(int state, int i) {
    return (state & (1 << i)) > 0;
}
bool check(int row, int state) {
    if (row < 0) return true;
    for (int j=0; j<m-1; j++)
        if (isset(state, j) && isset(state, j+1))
            return false;
    for (int j=0; j<m; j++)
        if (a[row][j] == 'x' && isset(state, j))
            return false;
    return true;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        memset(d, 0, sizeof(d));
        scanf("%d%d", &n, &m);
        for (int i=0;i<n;++i)
            scanf(" %s", a[i]);
        int ans = 0;
        for (int row=0; row<n; row++) {
            for (int state=0; state<(1<<m); state++) {
                if (!check(row, state)) continue;
                for (int pstate=0; pstate<(1<<m); pstate++) {
                    if (!check(row-1, pstate)) continue;
                    int cnt = 0;
                    bool ok = true;
                    for (int j=0; j<m; j++) {
                        if (isset(state, j)) {
                            cnt += 1;
                            if (j-1 >= 0 && isset(pstate, j-1)) ok = false;
                            if (j+1 < m && isset(pstate, j+1)) ok = false;
                        }
                    }
                    if (ok) {
                        if (row == 0)
                            d[row][state] = max(d[row][state], cnt);
                        else
                            d[row][state] = max(d[row][state], d[row-1][pstate] + cnt);
                    }
                }
            }
        }
        for (int state=0; state<(1<<m); state++)
            ans = max(ans, d[n-1][state]);
        printf("%d\n", ans);
    }
}
