#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, day = 0;
    scanf("%d%d%d", &A, &B, &C);
    while (C > 0) {
        day++;
        C -= A;
        if (day % 7 == 0) C -= B;
    }
    printf("%d", day);
}