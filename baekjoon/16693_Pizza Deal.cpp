#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, P1, R, P2;
    scanf("%d%d%d%d", &A, &P1, &R, &P2);
    if ((double)A / P1 > M_PI * R * R / P2) puts("Slice of pizza");
    else puts("Whole pizza");
}