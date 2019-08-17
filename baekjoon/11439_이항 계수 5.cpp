#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

bool c[4000001];

int main() {
    lint N, K, M, ans = 1;
    cin >> N >> K >> M;
    vector<int> p;
    for (int i=2;i<=N;++i) {
        if (!c[i]) {
            p.push_back(i);
            for (int j=2;i*j<=N;++j) {
                c[i*j] = 1;
            }
        }
    }
    for (int x : p) {
        lint cnt = 0;
        for (lint i=x;i<=N;i*=x) cnt += N / i;
        for (lint i=x;i<=K;i*=x) cnt -= K / i;
        for (lint i=x;i<=N-K;i*=x) cnt -= (N-K) / i;
        lint i = 1;
        while (cnt--) i = (i * x) % M;
        ans = (ans * i) % M;
    }
    cout << ans;
}