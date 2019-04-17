#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    while (C--) A ^= B;
    printf("%d", A);
}