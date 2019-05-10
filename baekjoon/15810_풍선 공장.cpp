#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long a[1000000];

bool check(long long time) {
    long long make = 0;
    for (int i=0;i<N;++i) {
        make += time / a[i];
    }
    return make >= M;
}

int main() {
    scanf("%lld %lld", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);

    long long l = 0, r = 1e+12;

    while (l <= r) {
        long long m = (l+r) / 2;
        if (check(m)) r = m-1;
        else l = m+1;
    }

    printf("%lld", l);
}