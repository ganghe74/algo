#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int a[2001], d[2001][2001];
int go(int i, int j) {
    if (i == j) return 1;
    if (i+1 == j) return a[i] == a[j];
    if (d[i][j] >= 0) return d[i][j];
    if (a[i] != a[j]) return d[i][j] = 0;
    else return d[i][j] = go(i+1, j-1);
}
int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &N);
    for (int i=1;i<=N;++i) scanf("%d", &a[i]);
    scanf("%d", &M);
    while (M--) {
        int S, E;
        scanf("%d%d", &S, &E);
        printf("%d\n", go(S, E));
    }
}