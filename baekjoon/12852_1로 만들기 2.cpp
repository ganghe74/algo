#include <bits/stdc++.h>
using namespace std;

int d[1000001], path[1000001];

int solve(int n) {
    if (n == 1) return 0;
    if (d[n]) return d[n];
    d[n] = solve(n-1) + 1;
    path[n] = n-1;
    for (int p : {2,3}) {
        if (n % p == 0) {
            if (solve(n/p) < d[n]) {
                d[n] = solve(n/p) + 1;
                path[n] = n/p;
            }
        }
    }
    return d[n];
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", solve(N));
    while (N) {
        printf("%d ", N);
        N = path[N];
    }
}