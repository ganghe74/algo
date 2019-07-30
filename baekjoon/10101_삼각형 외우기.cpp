#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    if (A == 60 && A == B && B == C) puts("Equilateral");
    else if (A + B + C == 180) {
        if (A == B || B == C || A == C) puts("Isosceles");
        else puts("Scalene");
    }
    else puts("Error");
}