#include <iostream>
using namespace std;
int main() {
    int cnt[1001] = {1};
    int N, M, L, ball = 0, ans = 0;
    scanf("%d%d%d", &N, &M, &L);
    while (true) {
        if (cnt[ball] == M) break;
        if (cnt[ball] % 2) ball += L;
        else ball -= L;
        if (ball < 0) ball += N;
        if (ball >= N) ball -= N;
        cnt[ball]++, ans++;
    }
    printf("%d", ans);
}