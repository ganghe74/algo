#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint t, n, m;
vector<string> a;
string s;

lint f(lint k, const string &prefix) {
    lint cnt = lower_bound(a.begin(), a.end(), prefix + string(k+1, '1')) - a.begin();
    cnt -= lower_bound(a.begin(), a.end(), prefix) - a.begin();
    return (1LL << k) - cnt;
}

string kth(lint rem, lint skip, string prefix) {
    if (!rem) return prefix;
    lint cnt = f(rem-1, prefix+'0');
    if (skip < cnt && cnt > 0)
        return kth(rem-1, skip, prefix+'0');
    return kth(rem-1, skip-cnt, prefix+'1');
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        lint k = (1LL << m) - n;
        a.resize(n);
        for (int i=0;i<n;++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        lint midx = (k-1) / 2;
        cout << kth(m, midx, "") << '\n';
    }
}
