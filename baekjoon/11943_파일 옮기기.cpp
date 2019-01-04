#include <iostream>
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;
int main() {
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    printf("%d", min(A+D, B+C));
}