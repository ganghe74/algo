#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, m = 100, s = 0;
        for (int i=0;i<7;++i) {
            scanf("%d", &x);
            if (x % 2 == 0) {
                m = min(m, x);
                s += x;
            }
        }
        printf("%d %d\n", s, m);
    }
}