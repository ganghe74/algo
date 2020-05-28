#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        int MAX = min(m, n/k);
        m -= MAX;
        k--;
        int MAX2 = (m + k - 1) / k;
        printf("%d\n", MAX - MAX2);
    }
}
