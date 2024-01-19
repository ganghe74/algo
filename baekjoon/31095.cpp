#include <bits/stdc++.h>
using namespace std;
using lint = int64_t;
const lint MOD = 1e9+7;

int T, N, K;
lint D[5001][5001], F[5001];

lint binom(int n, int k) {
  if (k == 0 || k == n) return 1;
  lint &ret = D[n][k];
  if (ret) return ret;
  return ret = (binom(n-1,k-1)+binom(n-1,k)) % MOD;
}

lint f(int n) {
  if (n == 0) return 1;
  lint &ret = F[n];
  if (ret) return ret;
  for (int i=1;i<=n;++i)
    ret = (ret + binom(n,i) * f(n-i)) % MOD;
  return ret;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N >> K;
    lint t = binom(N-1,K-1) * f(K-1) % MOD;
    cout << t * f(N-K) * (N == K ? 1 : 2) % MOD << '\n';
  }
}