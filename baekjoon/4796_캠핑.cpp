#include <iostream>
using namespace std;
int main() {
    int L, P, V, t = 0;
    while (++t) {
        int ans = 0;
        scanf("%d%d%d", &L, &P, &V);
        if (L == 0 && P == 0 && V == 0) break;
        while (V >= P) {
            V -= P;
            ans += L;
        }
        ans += min(L, V);
        printf("Case %d: %d\n", t, ans);
    }
}