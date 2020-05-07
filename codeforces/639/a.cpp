#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n == 1 || m == 1 || (n == 2 && m == 2)) puts("YES");
        else puts("NO");
    }
}
