#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, A = 100, B = 100;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) B -= a;
        if (a < b) A -= b;
    }
    printf("%d\n%d", A, B);
}