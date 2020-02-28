#include <bits/stdc++.h>
using namespace std;

int n, t[1000000];

void inc(int p) {
    for (t[p+=n]++;p>1;p>>=1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

vector<int> normalize(vector<int> a) {
    vector<int> s(a), ret(a.size());
    sort(s.begin(), s.end());
    for (int i=0;i<a.size();++i) {
        ret[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    a = normalize(a);
    for (int i=0;i<a.size();++i) {
        printf("%d\n", i+1-query(0,a[i]));
        inc(a[i]);
    }
}
