#include <iostream>
using namespace std;

int d[1000001] = {1, 1, 2};
int main() {
    for (int i=3;i<=1000000;++i) {
        d[i] = ((d[i-1] + d[i-2]) % 1000000009 + d[i-3]) % 1000000009;
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}