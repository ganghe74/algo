#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N, K;

lint cnt(lint x) {
    lint ret = 0;
    for (int i=1;i<=N;++i) ret += min(N, x/i);
    return ret;
}

int main() {
    cin >> N >> K;
    lint l = 1, r = N*N;
    while (l <= r) {
        lint mid = (l+r)/2;
        if (cnt(mid) <= K) l = mid + 1;
        else r = mid - 1;
    }
    while (cnt(l-1) >= K) l--;
    cout << l;
}