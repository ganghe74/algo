#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    while (N > 0) {
        ans <<= 1;
        ans += N & 1;
        N >>= 1;
    }
    printf("%d", ans);
}