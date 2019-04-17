#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    if (C % 2) printf("%d", A^B);
    else printf("%d", A);
}