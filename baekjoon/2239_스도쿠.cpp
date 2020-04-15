#include <bits/stdc++.h>
using namespace std;

int a[9][9];

bool dfs(int pos) {
    if (pos == 81) return true;
    int r = pos / 9;
    int c = pos % 9;

    if (a[r][c])
        return dfs(pos+1);

    vector<bool> ok(10, 1);
    for (int i=0;i<9;++i)
        ok[a[i][c]] = ok[a[r][i]] = false;
    for (int i=r/3*3;i<r/3*3+3;++i)
        for (int j=c/3*3;j<c/3*3+3;++j) ok[a[i][j]] = false;

    for (int i=1;i<=9;++i)
        if (ok[i]) {
            a[r][c] = i;
            if (dfs(pos+1)) return true;
            a[r][c] = 0;
        }
    return false;
}

int main() {
    for (int i=0;i<9;++i)
        for (int j=0;j<9;++j)
            scanf("%1d", &a[i][j]);

    dfs(0);
    for (int i=0;i<9;++i) {
        for (int j=0;j<9;++j) printf("%d", a[i][j]);
        puts("");
    }
}
