#include <bits/stdc++.h>
using namespace std;
int a[502], d[502][502];
int go(int i, int j) {
    if (i + 1 == j) return 0;
    if (d[i][j]) return d[i][j];
    for (int k=i+1;k<j;++k) {
        int temp = go(i, k) + go(k, j) + a[i] * a[k] * a[j];
        if (d[i][j] == 0 || temp < d[i][j])
            d[i][j] = temp;
    }
    return d[i][j];
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i=1;i<=N;++i) {
        scanf("%d%d", &a[i], &a[i+1]);
    }
    printf("%d", go(1, N+1));
}