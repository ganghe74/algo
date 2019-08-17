#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint d[10001];
int main() {
    d[0] = 1;
    for (int i=2;i<=10000;i+=2) {
        for (int j=0;j<i;j+=2) d[i] = (d[i] + d[j] * d[i-j-2]) % 987654321;
    }
    int N;
    scanf("%d", &N);
    printf("%lld", d[N]);
}