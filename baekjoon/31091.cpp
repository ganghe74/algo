#include <bits/stdc++.h>
using namespace std;

int N, k, A[500001], B[500001];

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> N;
  for (int i=0;i<N;++i) {
    cin >> k;
    if (k > 0) {
      A[0] += 1;
      A[k] -= 1;
    }
    else {
      A[-k+1] += 1;
    }
  }
  vector<int> C;
  B[0] = A[0];
  if (B[0] == 0) C.push_back(0);
  for (int i=1;i<=N;++i) {
    B[i] = B[i-1] + A[i];
    if (B[i] == i) C.push_back(i);
  }
  cout << C.size() << '\n';
  for (int x : C) cout << x << ' ';
}