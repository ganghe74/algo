#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        int A, B;
        scanf("%d%d", &A, &B);
        if (A == 0 && B == 0) break;
        if (A % B == 0) puts("multiple");
        else if (B % A == 0) puts("factor");
        else puts("neither");
    }
}