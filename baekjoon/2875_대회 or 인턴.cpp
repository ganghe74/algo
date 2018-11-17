#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, K, answer = 0;
    scanf("%d %d %d", &N, &M, &K);
    while (N+M>=K+3 && N>=2 && M>=1) {
        N -= 2;
        M -= 1;
        answer += 1;
    }
    printf("%d", answer);
}