#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint N, K;

lint cnt_column(lint c, lint x) {
    lint l = 1, r = N;
    while (l <= r) {
        lint mid = (l + r) / 2;
        if (c * mid <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

lint cnt_all(lint x) {
    lint ret = 0;
    for (lint c=1;c<=N;++c) ret += cnt_column(c, x);
    return ret;
}

int main() {
    scanf("%lld%lld", &N, &K);
    lint l = 1, r = N*N;
    while (l <= r) {
        lint mid = (l + r) / 2;
        lint cnt = cnt_all(mid);
        if (cnt <= K) l = mid + 1;
        else r = mid - 1;
    }
    while (cnt_all(l-1) >= K) l--;
    printf("%lld", l);
}