#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == 0 && l == r) puts("Not a moose");
    else if (l == r) printf("Even %d", l*2);
    else printf("Odd %d", max(l,r)*2);
}