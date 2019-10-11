#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, x, y, d[31] = {0, 1, 2};
    for (int i=3;i<=30;++i) d[i] = d[i-1] + d[i-2];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        y = 0;
        for (int i=29;i>0;--i) {
            if (x >= d[i]) {
                x -= d[i];
                y += d[i-1];
            }
        }
        printf("%d\n", y);
    }
}