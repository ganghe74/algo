#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, i, j, k, l;
    while (true) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a == b && b == c && c == d && d == 0) break;
        int cnt = 0;
        while (!(a == b && b == c && c == d)) {
            i = abs(a-b);
            j = abs(b-c);
            k = abs(c-d);
            l = abs(d-a);
            a = i; b = j; c = k; d = l;
            cnt++;
        }
        printf("%d\n", cnt);
    }
}