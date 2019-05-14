#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, p, q;
    scanf("%d%d%d", &l, &p, &q);
    double t = (double)l/(p+q);
    printf("%f", t * p);
}