#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int A, B;
        scanf("%d%d", &A, &B);
        printf("%d\n", A * A / B / B);
    }
}