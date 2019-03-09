#include <iostream>
using namespace std;
int a[20] = {1};
void solve(int n, int b = 19) {
    if (b == -1) return;
    solve(a[b] <= n ? n-a[b] : n, b-1);
    if (a[b] <= n) printf("%d ", b);
}
int main() {
    for (int i=1;i<20;++i) a[i] = a[i-1] * 2;
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        solve(n);
        printf("\n");
    }
}