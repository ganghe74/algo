#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[100];
    int N, M, ans = 0;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=0;i<N;++i) {
        for (int j=i+1;j<N;++j) {
            for (int k=j+1;k<N;++k) {
                if (a[i] + a[j] + a[k] <= M) {
                    ans = max(ans, a[i] + a[j] + a[k]);
                }
            }
        }
    }
    printf("%d", ans);
}