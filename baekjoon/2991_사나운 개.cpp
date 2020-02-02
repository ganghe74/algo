#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, D, t;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    for (int i=0;i<3;++i) {
        scanf("%d", &t);
        printf("%d\n", (((t + A + B - 1) % (A + B)) < A) + (((t + C + D - 1) % (C + D)) < C));
    }
}
