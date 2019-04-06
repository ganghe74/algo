#include <iostream>
using namespace std;
int main() {
    long long d[68] = {1,1,2,4};
    for (int i=4;i<68;++i) d[i] = d[i-1] + d[i-2] + d[i-3] + d[i-4];
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%lld\n", d[N]);
    }
}