#include <iostream>
using namespace std;
int main() {
    int N, m, M, T, R, time = 0;
    scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);
    int p = m;
    if (m+T > M) N = -1, time = -1;
    while (N > 0) {
        if (p+T <= M) {
            p += T;
            N--;
        }
        else p = max(p-R, m);
        time++;
    }
    printf("%d", time);
}