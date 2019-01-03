#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    B += C;
    A += B / 60;
    B %= 60;
    A %= 24;
    printf("%d %d", A, B);
}