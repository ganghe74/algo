#include <iostream>
using namespace std;
int main() {
    int K, N, M;
    scanf("%d%d%d", &K, &N, &M);
    printf("%d", max(K*N-M, 0));
}