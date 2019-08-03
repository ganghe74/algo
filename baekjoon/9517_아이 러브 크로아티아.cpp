#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N, T, now = 0;
    char Z;
    scanf("%d%d", &K, &N);
    K--;
    while (N--) {
        scanf("%d %c", &T, &Z);
        now += T;
        if (now >= 210) break;
        if (Z == 'T') K = (K+1) % 8;
    }
    printf("%d", K+1);
}