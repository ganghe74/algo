#include <bits/stdc++.h>
using namespace std;
int main() {
    double c, r1, r2;
    scanf("%lf%lf%lf", &c, &r1, &r2);
    double a2 = c*c/((r2/r1)*(r2/r1) + 1);
    double b2 = c*c - a2;
    int a = (int)sqrt(a2);
    int b = (int)sqrt(b2);
    printf("%d %d", a, b);
}