#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    while (N > 0) {
        int k = 1;
        while ((k+1) * (k+2) / 2 <= N) k++;
        N -= k * (k+1) / 2;
        ans += k;
    }
    printf("%d", ans);
}