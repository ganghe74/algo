#include <iostream>
using namespace std;
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        N = (N+1) / 2;
        printf("%d\n", N*N);
    }
}