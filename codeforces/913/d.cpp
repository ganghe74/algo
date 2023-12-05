#include <bits/stdc++.h>
using namespace std;

int t, n, L[200001], R[200001];

bool check(int k) {
    int l=0, r=0;
    for (int i=0;i<n;++i) {
        if (R[i] < l-k) return false;
        if (L[i] > r+k) return false;
        int nl = 2e9, nr = -2e9;
        if (l <= L[i] && L[i] <= r)
            nl = L[i];
        else if (abs(L[i]-l) <= k || abs(L[i]-r) <= k)
            nl = L[i];
        else
            nl = l-k;
        if (l <= R[i] && R[i] <= r)
            nr = R[i];
        else if (abs(R[i]-l) <= k || abs(R[i]-r) <= k)
            nr = R[i];
        else
            nr = r+k;
        l = nl;
        r = nr;
    }
    return true;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;++i) cin >> L[i] >> R[i];
    int l = 0, r = 1e9;
    while (r-l > 1) {
        int mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (check(l)) r = l;
    cout << r << '\n';
  }
}