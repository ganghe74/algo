#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (A+B>=2*C) A -= 2 * C;
    printf("%d", A+B);
}