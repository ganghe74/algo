#include <iostream>
using namespace std;
int main() {
    int A, B;
    while (true) {
        scanf("%d%d", &A, &B);
        if (A == 0 && B == 0) break;
        printf("%d %d / %d\n", A/B, A%B, B);
    }
}