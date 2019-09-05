#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, d, n, s, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &d, &n, &s, &p);
        if (d + n * p == s * n) puts("does not matter");
        else if (d + n * p < s * n) puts("parallelize");
        else puts("do not parallelize");
    }
}