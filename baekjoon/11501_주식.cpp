#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        vector<int> a(N+1), M(N+1);
        for (int i=0;i<N;++i) scanf("%d", &a[i]);
        long long ans = 0;
        for (int i=N-1;i>=0;--i) {
            if (a[i] <= M[i+1]) ans += M[i+1] - a[i];
            M[i] = max(a[i], M[i+1]);
        }
        printf("%lld\n", ans);
    }
}