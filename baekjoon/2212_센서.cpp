#include <bits/stdc++.h>
using namespace std;
int N, K;
long long ans;
int main() {
    scanf("%d%d", &N, &K);
    vector<int> a(N), d;
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i=1;i<a.size();++i) d.push_back(a[i]-a[i-1]);
    sort(d.begin(), d.end());
    while (--K && d.size()) d.pop_back();
    for (int x : d) ans += x;
    printf("%lld", ans);
}
