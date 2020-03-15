#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];
char s1[1002], s2[1002];

void trace(int i, int j) {
    if (!i || !j) return;
    if (s1[i] == s2[j]) {
        trace(i-1, j-1);
        putchar(s1[i]);
    }
    else (d[i-1][j] > d[i][j-1]) ? trace(i-1, j) : trace(i, j-1);
}

int main() {
    scanf("%s %s", s1+1, s2+1);
    int n = strlen(s1+1);
    int m = strlen(s2+1);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (s1[i] == s2[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
    printf("%d\n", d[n][m]);
    trace(n, m);
}
