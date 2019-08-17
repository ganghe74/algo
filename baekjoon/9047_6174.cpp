#include <bits/stdc++.h>
using namespace std;

int f(int N) {
    if (N == 6174) return 0;
    int a[4] = {N / 1000, N % 1000 / 100, N % 100 / 10, N % 10};
    sort(a, a+4);
    return f(a[3]*1000 + a[2]*100 + a[1]*10 + a[0] - (a[0]*1000 + a[1]*100 + a[2]*10 + a[3])) + 1;
}

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", f(N));
    }
}