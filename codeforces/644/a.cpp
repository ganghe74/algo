#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        int m = max(min(a, b)*2, max(a, b));
        printf("%d\n", m*m);
    }
}
