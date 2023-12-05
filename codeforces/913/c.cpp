#include <bits/stdc++.h>
using namespace std;

int t, n, ans, cnt[26];
string s;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    ans = 0;
    fill(cnt, cnt+26, 0);
    cin >> n >> s;
    for (auto c : s)
      ++cnt[c-'a'];
    priority_queue<int> pq;
    for (int i=0;i<26;++i)
        if (cnt[i])
            pq.push(cnt[i]);
    while (pq.size() > 1) {
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      a--; b--;
      if (a > 0) pq.push(a);
      if (b > 0) pq.push(b);
    }
    pq.push(0);
    cout << pq.top() << '\n';
  }
}