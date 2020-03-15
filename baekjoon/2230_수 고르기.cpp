#include <bits/stdc++.h>
using namespace std;

int N, M, a[100000];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    int i=0, j=0;
    while (a[j]-a[i] < M) j++;
    int ans = a[j]-a[i];
    while (++j < N) {
        while (a[j]-a[i+1] >= M) i++;
        ans = min(ans, a[j]-a[i]);
    }
    printf("%d", ans);
}
