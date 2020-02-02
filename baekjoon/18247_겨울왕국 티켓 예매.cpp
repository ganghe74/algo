#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, M;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        if (M < 4 || N < 12) puts("-1");
        else printf("%d\n", 11 * M + 4);
    }
}
