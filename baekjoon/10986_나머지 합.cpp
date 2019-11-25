#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    lint N, M, x, ans = 0, s = 0, cnt[1000] = {1};
    cin >> N >> M;
    for (int i=1;i<=N;++i) {
        cin >> x;
        s = (s + x) % M;
        cnt[s]++;
    }
    for (int i=0;i<M;++i) ans += cnt[i] * (cnt[i]-1) / 2;
    cout << ans;
}