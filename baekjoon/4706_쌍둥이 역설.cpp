#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        double ta, tb;
        scanf("%lf%lf", &ta, &tb);
        if (ta < 1.0) break;
        printf("%.3lf\n", sqrt(1-(tb*tb)/(ta*ta)));
    }
}