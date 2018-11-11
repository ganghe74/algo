#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, S = 0;
    scanf("%d", &N);
    int A[N], B[N];;
    for (int i=0;i<N;++i) scanf("%d", &A[i]);
    for (int i=0;i<N;++i) scanf("%d", &B[i]);
    sort(A, A+N);
    sort(B, B+N);
    for (int i=0;i<N;++i) S += A[i] * B[N-i-1];
    printf("%d", S);
}