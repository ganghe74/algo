#include <iostream>
using namespace std;

int cache[1000][1000];
int bino(int n, int r) {
    if (r==0 || n==r) return 1;
    if (cache[n][r] != -1) return cache[n][r];
    cache[n][r] = (bino(n-1,r-1) + bino(n-1,r)) % 10007;;
    return cache[n][r];
}

int main() {
    for (int i=0;i<1000;++i) {
        for (int j=0;j<1000;++j) cache[i][j] = -1;
    }
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d", bino(N, K));
}