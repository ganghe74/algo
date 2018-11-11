#include <iostream>
using namespace std;
int main() {
    int d[101] = {0,1,2};
    for (int i=3;i<=100;++i) d[i] = (d[i-1] + d[i-2]) % 1000000007;
    int C, n;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}