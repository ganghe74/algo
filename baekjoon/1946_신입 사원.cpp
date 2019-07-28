#include <iostream>
using namespace std;
int a[100001];
int main() {
    int T, N, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i=0;i<N;++i) {
            scanf("%d%d", &x , &y);
            a[x] = y;
        }
        int M = 1e9, ans = 0;
        for (int i=1;i<=N;++i) {
            if (a[i] < M) {
                M = a[i];
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}