#include <bits/stdc++.h>
using namespace std;
int T, W;
int a[1001], d[1001][31];
int solve(int sec, int turn) {
    if (sec == T+1 && turn <= W) return 0;
    if (turn > W) return 0;
    if (d[sec][turn] != -1) return d[sec][turn];
    int where = turn % 2 + 1;
    d[sec][turn] =max(solve(sec+1, turn), solve(sec+1, turn+1)) + (where == a[sec] ? 1 : 0);
    return d[sec][turn];
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &T, &W);
    for (int i=1;i<=T;++i) scanf("%d", &a[i]);
    printf("%d", max(solve(0,0), solve(0,1)));
}