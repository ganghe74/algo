#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, M = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        M = max(M, x);
    }
    printf("%d", M);
}