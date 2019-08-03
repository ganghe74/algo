#include <bits/stdc++.h>
using namespace std;
int N, a[1001];
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    int idx = 0, ans = 0;
    while (idx < N) {
        int start = idx;
        while (a[idx] < a[idx+1]) idx++;
        ans = max(ans, a[idx]-a[start]);
        idx++;
    }
    printf("%d", ans);
}