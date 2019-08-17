#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s, tc, t;
    scanf("%d%d%d%d", &h, &m, &s, &tc);
    t = h * 3600 + m * 60 + s;
    while (tc--) {
        int q, c;
        scanf("%d", &q);
        if (q == 3) printf("%d %d %d\n", t / 3600, t % 3600 / 60, t % 60);
        else {
            scanf("%d", &c);
            if (q == 1) t += c;
            else t -= c;
            if (t >= 86400) t %= 86400;
            while (t < 0) t += 86400;
        }
    }
}