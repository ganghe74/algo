#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c=0;
    scanf("%d%d", &n, &m);
    vector<int> a(n), b(m);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<m;++i) scanf("%d", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0;i<n;++i) {
        auto pi = equal_range(b.begin(), b.end(), a[i]);
        c += pi.second - pi.first;
    }
    printf("%d", a.size()+b.size()-c*2);
}