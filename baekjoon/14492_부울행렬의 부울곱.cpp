#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int A[N][N], B[N][N];
    int answer = 0;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &A[i][j]);
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &B[i][j]);
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            bool value = false;
            for (int n=0;n<N;++n) value = value || (A[i][n] && B[n][j]);
            if (value) answer++;
        }
    }
    printf("%d", answer);
}