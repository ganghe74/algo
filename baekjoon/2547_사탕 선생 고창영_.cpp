#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint T, N, x;
    cin >> T;
    while (T--) {
        lint s = 0;
        cin >> N;
        for (lint i=0;i<N;++i) {
            cin >> x;
            s = (s + (x % N)) % N;
        }
        if (s == 0) puts("YES");
        else puts("NO");
    }
}