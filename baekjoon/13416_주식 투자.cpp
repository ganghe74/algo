#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, a, b, c, s = 0;
        scanf("%d", &N);
        while (N--) {
            scanf("%d%d%d", &a, &b, &c);
            s += max({a, b, c, 0});
        }
        printf("%d\n", s);
    }
}