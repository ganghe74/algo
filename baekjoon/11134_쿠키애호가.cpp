#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, C;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &C);
        printf("%d\n", (N+C-1)/C);
    }
}