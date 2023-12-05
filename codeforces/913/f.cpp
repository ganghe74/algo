#include <bits/stdc++.h>
using namespace std;

int t, n, a[100005];

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int mx = 0, mn = 2e9;
    for (int i=0;i<n;++i) {
      cin >> a[i];
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
    int inc=0, dec=0;
    for (int i=1;i<2*n;++i) {
      if (inc >= n-1 || dec >= n-1)
        break;
      if (a[(i-1)%n] <= a[i%n]) inc++;
      else inc = 0;
      if (a[(i-1)%n] >= a[i%n]) dec++;
      else dec = 0;
    }
    if (inc < n-1 && dec < n-1) {
      cout << "-1\n";
      continue;
    }
    int ans = 1e9;
    for (int i=0;i<n;++i) {
      if (a[(n-i)%n] == mn && a[(2*n-i-1)%n] == mx)
        ans = min(ans, i);
      if (a[i] == mn && a[(i+n-1)%n] == mx)
        ans = min(ans, i+2);
      if (a[(n-i)%n] == mx && a[(2*n-i-1)%n] == mn)
        ans = min(ans, i+1);
      if (a[i] == mx && a[(i+n-1)%n] == mn)
        ans = min(ans, i+1);
    }
    assert(ans != 1e9);
    cout << ans << '\n';
  }
}