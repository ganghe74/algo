#include <bits/stdc++.h>
using namespace std;

int main() {
    double t0, t1;
    scanf("%lf", &t0);
    while (true) {
        scanf("%lf", &t1);
        if (t1 == 999) break;
        printf("%.2lf\n", t1-t0);
        t0 = t1;
    }
}