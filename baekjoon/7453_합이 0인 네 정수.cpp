#include <bits/stdc++.h>
using namespace std;
int n, a[4000], b[4000], c[4000], d[4000];
long long ans;
vector<int> ab, cd;
int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    }
    sort(cd.begin(), cd.end());
    for (int num : ab) {
        auto range = equal_range(cd.begin(), cd.end(), -num);
        ans +=  range.second - range.first;
    }
    printf("%lld", ans);
}