#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C;
    scanf("%d%d%d", &A ,&B, &C);
    if (B >= C) {
        puts("-1");
    }
    else {
        printf("%d", A / (C - B) + 1);
    }
}