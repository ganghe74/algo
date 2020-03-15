#include <bits/stdc++.h>
using namespace std;

int N, d[10000][10], p[10000][10], a[10000][10];
char s[10001], t[10001];

int solve(int n, int bias) {
    if (n == N) return 0;
    int &ret = d[n][bias];
    if (ret != -1) return ret;
    int l = solve(n+1, (t[n]-s[n]+10)%10) + (t[n]-s[n]-bias+20)%10;
    int r = solve(n+1, bias) + (s[n]+bias-t[n]+10)%10;
    p[n][bias] = (l < r) ? (t[n]-s[n]+10)%10 : bias;
    a[n][bias] = (l < r) ? (t[n]-s[n]-bias+20)%10 : -((s[n]+bias-t[n]+10)%10);
    return ret = min(l, r);
}

void trace(int n, int bias) {
    if (n == N) return;
    printf("%d %d\n", n+1, a[n][bias]);
    trace(n+1, p[n][bias]);
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d %s %s", &N, s, t);
    printf("%d\n", solve(0, 0));
    trace(0, 0);
}
