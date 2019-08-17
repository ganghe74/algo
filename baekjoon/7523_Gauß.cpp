#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
    int T;
    lint n, m;
    scanf("%d", &T);
    for (int tc=1;tc<=T;++tc) {
        scanf("%lld%lld", &n, &m);
        printf("Scenario #%d:\n", tc);
        printf("%lld\n\n", m*(m+1)/2 - n*(n-1)/2);
    }
}