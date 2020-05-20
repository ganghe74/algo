#include <bits/stdc++.h>
using namespace std;

int T, n, m, a[1000], b[1000];
unordered_map<int,int> cnt;

int main() {
    scanf("%d", &T);
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i=0;i<m;++i) scanf("%d", &b[i]);
    
    for (int i=0;i<n;++i) {
        int s = 0;
        for (int j=i;j<n;++j) {
            s += a[j];
            cnt[s]++;
        }
    }

    long long ans = 0;
    for (int i=0;i<m;++i) {
        int s = 0;
        for (int j=i;j<m;++j) {
            s += b[j];
            ans += cnt[T-s];
        }
    }
    printf("%lld", ans);
}
