#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d", max(d-a,0) + max(e-b,0) + max(f-c,0));
}