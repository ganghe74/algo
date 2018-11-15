#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int d[101] = {1,1};

int main() {
    for (int i=2;i<=100;++i) d[i] = (d[i-1] + d[i-2]) % MOD;
    int C, n, answer;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &n);
        if (n%2 == 1) answer = (d[n] - d[n/2] + MOD) % MOD;
        else {
            answer = d[n];
            answer = (answer - d[n/2] + MOD) % MOD;
            answer = (answer - d[n/2-1] + MOD) % MOD;
        }
        printf("%d\n", answer);
    }
}