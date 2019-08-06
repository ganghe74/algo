#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 0, n;
    while (++tc) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d. ", tc);
        if (3*n % 2 == 0) printf("even ");
        else printf("odd ");
        printf("%d\n", (3*n+1)/2*3/9);
    }
}