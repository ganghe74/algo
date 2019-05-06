#include <iostream>
using namespace std;
int main() {
    int N, M, ans = 0;
    scanf("%d%d", &N, &M);
    while (N > 0) {
        ans += N;
        N /= M;
    }
    printf("%d", ans);
}