#include <bits/stdc++.h>
using namespace std;
int main() {
    int X, N, use, sum = 0;
    scanf("%d%d", &X, &N);
    while (N--) {
        scanf("%d", &use);
        sum = sum + X - use;
    }
    printf("%d", sum + X);
}