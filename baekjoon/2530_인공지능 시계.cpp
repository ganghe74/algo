#include <iostream>
using namespace std;
int main() {
    int A, B, C, totalSec;
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &totalSec);
    totalSec += A * 3600 + B * 60 + C;
    totalSec %= 86400;
    printf("%d ", totalSec / 3600);
    totalSec %= 3600;
    printf("%d ", totalSec / 60);
    totalSec %= 60;
    printf("%d", totalSec);
}