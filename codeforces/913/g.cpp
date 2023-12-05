#include <bits/stdc++.h>
using namespace std;

int t, n, x, a[200005], ind[200005], p[200005];
vector<int> ans;
string s;

void toggle(int u) {
  s[u] = (s[u] == '0' ? '1' : '0');
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    fill(ind, ind+n, 0);
    ans.clear();
    for (int i=0;i<n;++i) {
      cin >> x;
      a[i] = x-1;
      ind[x-1]++;
    }

    queue<int> q;

    for (int i=0;i<n;++i) {
      if (ind[i] == 0) {
        q.push(i);
      }
    }

    while (q.size()) {
      int u = q.front(); q.pop();
      if (s[u] == '1') {
        ans.push_back(u);
        toggle(u);
        toggle(a[u]);
      }
      if (--ind[a[u]] == 0) {
        q.push(a[u]);
      }
    }

    for (int i=0;i<n;++i) {
      if (s[i] == '0' || ind[i] == 0) continue;
      vector<int> A, B;
      int u = i;
      do {
        if (s[u] == '1') {
          A.push_back(u);
          toggle(u);
          toggle(a[u]);
        }
        else B.push_back(u);
        ind[u] = 0;
        u = a[u];
      } while(u != i);
      if (A.size() < B.size())
        for (int i : A) ans.push_back(i);
      else
        for (int i : B) ans.push_back(i);
    }

    if (s.find('1') != string::npos) {
      cout << "-1\n";
      continue;
    }

    cout << ans.size() << '\n';
    for (int i : ans) cout << i+1 << ' ';
    cout << '\n';
  }
}