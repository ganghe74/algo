#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, ans = 0;
        scanf("%d", &N);
        ans += (N/3) * (N/3+1) / 2 * 3;
        ans += (N/7) * (N/7+1) / 2 * 7;
        ans -= (N/21) * (N/21+1) / 2 * 21;
        printf("%d\n", ans);
    }
}