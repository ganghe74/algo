#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, x;
    double avg = 0, exp = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        avg += x;
        exp += x * (1.0 / N);
    }
    avg /= N;
    if (exp == 0) puts("divide by zero");
    else printf("%.2lf", avg / exp);
}