#include <iostream>
using namespace std;
const int MOD = 1e9+7;
int d[51] = {1, 1};
int main() {
    for (int i=2;i<=50;++i) d[i] = (d[i-1] + d[i-2] + 1) % MOD;
    int N;
    scanf("%d", &N);
    printf("%d", d[N]);
}