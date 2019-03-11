#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    printf("%d", max(abs(A-B), abs(B-C))-1);
}