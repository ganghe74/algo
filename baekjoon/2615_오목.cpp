#include <bits/stdc++.h>
using namespace std;
int dr[] = {0,1,1,-1};
int dc[] = {1,1,0,1};
int a[30][30];
bool check(int r, int c) {
    for (int k=0;k<4;++k) {
        bool flag = true;
        if (a[r][c] == a[r+dr[k]*-1][c+dc[k]*-1] || a[r][c] == a[r+dr[k]*5][c+dc[k]*5]) continue;
        for (int i=1;i<5;++i) {
            if (a[r][c] != a[r+dr[k]*i][c+dc[k]*i]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}
int main() {
    for (int i=5;i<24;++i) {
        for (int j=5;j<24;++j) scanf("%d", &a[i][j]);
    }
    for (int i=5;i<24;++i) {
        for (int j=5;j<24;++j) {
            if (a[j][i] > 0) {
                if (check(j, i)) {
                    printf("%d\n%d %d", a[j][i], j-4, i-4);
                    return 0;
                }
            }
        }
    }
    puts("0");
}