#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    while (true) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (!a && !b && !c && !d) break;
        printf("%d %d\n", c-b, d-a);
    }
}
