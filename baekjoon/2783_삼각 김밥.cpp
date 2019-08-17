#include <bits/stdc++.h>
using namespace std;
int main() {
    int X, Y, N, a, b;
    scanf("%d%d%d", &X, &Y, &N);
    double g = (double)X / Y;
    while (N--) {
        scanf("%d%d", &a, &b);
        g = min(g, (double)a / b);
    }
    printf("%lf", g * 1000);
}