#include <iostream>
using namespace std;
int coins[100];
int d[10001];
int main() {
    d[0] = 1;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0;i<n;++i) scanf("%d", &coins[i]);
    for (int i=0;i<n;++i) {
        for (int j=0;j<=k;++j) {
            if (j >= coins[i]) {
                d[j] = d[j] + d[j-coins[i]];
            }
        }
    }
    printf("%d", d[k]);
}