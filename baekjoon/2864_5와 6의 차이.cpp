#include <iostream>
using namespace std;
int main() {
    char A[8], B[8];
    scanf("%s %s", A, B);
    for (int i=0;i<8;++i) {
        if (A[i] == '6') A[i] = '5';
        if (B[i] == '6') B[i] = '5';
    }
    printf("%d ", atoi(A) + atoi(B));
    for (int i=0;i<8;++i) {
        if (A[i] == '5') A[i] = '6';
        if (B[i] == '5') B[i] = '6';
    }
    printf("%d", atoi(A) + atoi(B));
}