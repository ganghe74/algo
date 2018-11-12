#include <bits/stdc++.h>
using namespace std;

int d[301][301];

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int divide(int N, int M) {
    if (N == 1 && M == 1) return 0;
    if (N<M) swap(N, M);
    int& ret = d[N][M];
    if (N%2 == 0) ret = divide(N/2, M) * 2 + 1;
    else ret = divide(N/2, M) + divide(N/2+1, M) + 1;
    return ret;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%d", divide(N, M));
}