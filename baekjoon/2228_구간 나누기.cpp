#include <bits/stdc++.h>
using namespace std;
const int MIN = -2e9;
int N, M;
bool c[101][51];
int a[101], s[101], d[101][51];

int solve(int n, int m) {
    if (m == 0) return 0;
    if (n <= 0) return MIN;
    if (c[n][m]) return d[n][m];
    c[n][m] = true;
    int &ans = d[n][m];
    ans = solve(n-1, m);
    for (int i=1;i<=n;++i) {
        int temp = solve(i-2, m-1) + s[n] - s[i-1];
        if (ans < temp) ans = temp;
    }
    return ans;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;++i) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    printf("%d", solve(N, M));
}