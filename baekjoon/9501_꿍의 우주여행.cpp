#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, D;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &D);
        int cnt = 0;
        while (N--) {
            int v, f, c;
            scanf("%d%d%d", &v, &f, &c);
            if ((double)v * f / c >= D) cnt++;
        }
        printf("%d\n", cnt);
    }
}