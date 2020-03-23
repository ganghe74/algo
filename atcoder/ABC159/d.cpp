#include <bits/stdc++.h>
using namespace std;

int N, x, a[200001], cnt[200001];
long long ways;

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
        ways += cnt[a[i]];
        cnt[a[i]]++;
    }

    for (int i=0;i<N;++i) {
        ways -= cnt[a[i]] - 1;
        printf("%lld\n", ways);
        ways += cnt[a[i]] - 1;
    }
    
}
