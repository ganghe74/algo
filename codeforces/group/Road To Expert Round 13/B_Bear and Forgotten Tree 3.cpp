#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, h;
    scanf("%d%d%d", &n, &d, &h);
    if (d > 2 * h || (n != 2 && d == 1 && h == 1)) {
        puts("-1");
        return 0;
    }
    int node = 1;
    while (++node <= h+1) printf("%d %d\n", node-1, node);
    if (node <= d+1) {
        printf("1 %d\n", node);
        while (++node <= d+1) printf("%d %d\n", node-1, node);
    }
    int x = 1;
    if (d == h) x = 2;
    while (node <= n) printf("%d %d\n", x, node++);
}