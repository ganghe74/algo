#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int d[n+1][2] = {{0,0}, {0,1}};
    for (int i=2;i<=n;++i) {
          d[i][0] = d[i-2][1] % 1000000009;
          d[i][1] = (d[i-1][0] + d[i-1][1]) % 1000000009;
    }
    printf("%d", (d[n][0] + d[n][1]) % 1000000009);
}