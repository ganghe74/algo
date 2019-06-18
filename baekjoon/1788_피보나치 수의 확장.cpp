#include <iostream>
using namespace std;
const int MOD = 1e+9;
int a[1000001] = {0,1};
int main() {
    for (int i=2;i<=1000000;++i) a[i] = (a[i-2] + a[i-1]) % MOD;
    int n;
    scanf("%d", &n);
    if (n == 0) puts("0");
    else if (n < 0 && n % 2 == 0) puts("-1");
    else puts("1");
    printf("%d", a[abs(n)]);
}