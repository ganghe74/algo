#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
lint x[100001], y[100001];

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%lld %lld", &x[i], &y[i]);
    x[N] = x[0]; y[N] = y[0];
    lint s = 0;
    for (int i=0;i<N;++i) {
        s += x[i] * y[i+1];
        s -= y[i] * x[i+1];
    }
    printf("%lld.%d", abs(s/2), (s%2)?5:0);
}
