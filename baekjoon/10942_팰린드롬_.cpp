#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int a[2001], d[2001][2001];
int main() {
    scanf("%d", &N);
    for (int i=1;i<=N;++i) scanf("%d", &a[i]);
    for (int i=1;i<=N;++i) d[i][i] = 1;
    for (int i=1;i<=N-1;++i) d[i][i+1] = (a[i] == a[i+1]);
    for (int k=3;k<=N;++k) {
        for (int i=0;i+k-1<=N;++i) {
            d[i][i+k-1] = d[i+1][i+k-2] && (a[i] == a[i+k-1]);
        }
    }
    scanf("%d", &M);
    while (M--) {
        int S, E;
        scanf("%d%d", &S, &E);
        printf("%d\n", d[S][E]);
    }
}