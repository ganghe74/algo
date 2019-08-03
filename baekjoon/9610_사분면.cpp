#include <bits/stdc++.h>
using namespace std;
int n, q1, q2, q3, q4, axis;
int main() {
    scanf("%d", &n);
    while (n-- ) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0 || y == 0) axis++;
        else if (x > 0 && y > 0) q1++;
        else if (x < 0 && y > 0) q2++;
        else if (x < 0 && y < 0) q3++;
        else q4++;
    }
    printf("Q1: %d\n", q1);
    printf("Q2: %d\n", q2);
    printf("Q3: %d\n", q3);
    printf("Q4: %d\n", q4);
    printf("AXIS: %d", axis);
}