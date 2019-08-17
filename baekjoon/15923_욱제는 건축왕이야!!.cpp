#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, x[20], y[20], l = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d%d", &x[i], &y[i]);
    for (int i=1;i<N;++i) l += abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
    l += abs(x[0]-x[N-1]) + abs(y[0]-y[N-1]);
    printf("%d", l);
}