#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    deque<pair<char,int>> ldq, udq;
    for (int i=0;i<s.size();++i) {
        char c = s[i];
        if (c == 'b') {
            if(ldq.size())
                ldq.pop_back();
        }
        else if (c == 'B') {
            if (udq.size())
                udq.pop_back();
        }
        else if (islower(c))
            ldq.push_back({c, i});
        else
            udq.push_back({c, i});
    }
    while (ldq.size() && udq.size()) {
        auto [l, i] = ldq.front();
        auto [u, j] = udq.front();
        if (i < j) {
            cout << l;
            ldq.pop_front();
        } else {
            cout << u;
            udq.pop_front();
        }
    }
    while (ldq.size()) {
        auto [l, i] = ldq.front();
        cout << l;
        ldq.pop_front();
    }
    while (udq.size()) {
        auto [r, i] = udq.front();
        cout << r;
        udq.pop_front();
    }
    cout << '\n';
  }
}