#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n == 1) puts("0");
        else if (n == 2) printf("%d\n", m);
        else printf("%d\n", m*2);
    }
}
