#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using int128 = __int128_t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lint T, N, x;
    cin >> T;
    while (T--) {
        int128 s = 0;
        cin >> N;
        for (lint i=0;i<N;++i) {
            cin >> x;
            s += x;
        }
        if (s % N == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}