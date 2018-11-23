#include <iostream>
using namespace std;
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N], B[M], C[N+M];
    for (int i=0;i<N;++i) scanf("%d", &A[i]);
    for (int i=0;i<M;++i) scanf("%d", &B[i]);
    int i = 0, j = 0, k = 0;
    while (i < N && j < M) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        }
        else {
            C[k++] = B[j++];
        }
    }
    while (i < N) C[k++] = A[i++];
    while (j < M) C[k++] = B[j++];
    for (int i=0;i<N+M;++i) printf("%d ", C[i]);
}