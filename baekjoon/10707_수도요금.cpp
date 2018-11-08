#include <iostream>
using namespace std;
int main() {
    int A, B, C, D, P;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
    int X = A * P;
    int Y = (P<C)?B:(B+D*(P-C));
    if (X < Y) printf("%d", X);
    else printf("%d", Y);
}