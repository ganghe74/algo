#include <iostream>
using namespace std;
bool c[1001];
int main() {
    int N, M, k, ans = 0;
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d", &k);
        for (int i=k;i<=N;i+=k) {
            if (!c[i]) {
                c[i] = 1;
                ans += i;
            }
        }
    }
    printf("%d", ans);
}