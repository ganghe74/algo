#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a >= 8 && d >= 8 && b == c) puts("ignore");
    else puts("answer");
}