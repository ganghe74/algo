#include <bits/stdc++.h>
using namespace std;

int T, k, p[100], n[100], d[101][10001];

int main() {
    scanf("%d%d", &T, &k);
    for (int i=0;i<k;++i) scanf("%d%d", &p[i], &n[i]);
    d[0][0] = 1;
    for (int i=0;i<k;++i)
        for (int j=0;j<=n[i];++j) {
            int val = p[i] * j;
            for (int k=0;k<=T-val;++k)
                d[i+1][k+val] += d[i][k];
        }
    printf("%d", d[k][T]);
}
