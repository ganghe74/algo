#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N;
    cout << (((N+1) % (N%100) == 0) ? "Good" : "Bye") << '\n';
  }
}