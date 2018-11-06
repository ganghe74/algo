#include <iostream>
using namespace std;
long long d[91] = {0,1};
int main() {
    for (int i=2;i<=90;++i) {
        d[i] = d[i-1] + d[i-2];
    }
    int n;
    scanf("%d", &n);
    printf("%lld", d[n]);
}