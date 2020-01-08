#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    while (true) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 && a == b && b == c) break;
        c -= a;
        if (c % b == 0) printf("%d\n", c/b+1);
        else puts("X");
    }
}