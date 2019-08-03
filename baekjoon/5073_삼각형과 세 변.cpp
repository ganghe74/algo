#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    while (true) {
        scanf("%d%d%d", &a, &b, &c);
        if (!a && !b && !c) break;
        if (a+b+c-2*max({a,b,c}) <= 0) puts("Invalid");
        else if (a == b && b == c) puts("Equilateral");
        else if (a == b || b == c || c == a) puts("Isosceles");
        else puts("Scalene");
    }
}