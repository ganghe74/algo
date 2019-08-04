#include <bits/stdc++.h>
using namespace std;

int a[100000];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N, S;
    scanf("%d%d", &N, &S);
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
        a[i] = abs(a[i] - S);
    }
    int ans = 0;
    for (int i=0;i<N;++i) ans = gcd(ans, a[i]);
    printf("%d", ans);
}