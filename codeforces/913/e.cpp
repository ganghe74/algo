#include <bits/stdc++.h>
using namespace std;

int t, n, cnt[10];

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  for (int a=0;a<=9;++a)
    for (int b=0;a+b<=9;++b)
      for (int c=0;a+b+c<=9;++c)
        cnt[a+b+c]++;

  cin >> t;
  while (t--) {
    cin >> n;
    int64_t ans = 1;
    while (n) {
      ans *= cnt[n % 10];
      n /= 10;
    }
    cout << ans << '\n';
  }

}