#include <bits/stdc++.h>
using namespace std;

int n, a[6];
set<int> d[1<<6];

set<int> solve(int mask) {
    set<int> &ans = d[mask];
    if (ans.size() > 0)
        return ans;
    if (mask == 0)
        return ans;
    for (int i=0;i<(1<<n);++i) {
        int first = i & mask;
        int second = (~first) & mask;
        if (first == 0 || second == 0)
            continue;
        solve(first);
        solve(second);
        for (int x : d[first]) {
            for (int y : d[second]) {
                if (x != 0)
                    ans.insert(y/x);
                if (y != 0)
                    ans.insert(x/y);
                ans.insert(x+y);
                ans.insert(x-y);
                ans.insert(y-x);
                ans.insert(x*y);
            }
        }
    }
    return ans;
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i=2;i*i<=x;++i)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &a[i]);
        d[1<<i].insert(a[i]);
    }
    int pmin = INT32_MAX;
    int pmax = -1;
    auto ans = solve((1<<n)-1);
    for (int x : ans) {
        if (is_prime(x)) {
            pmin = min(pmin, x);
            pmax = max(pmax, x);
        }
    }
    if (pmax == -1) puts("-1");
    else printf("%d\n%d", pmin, pmax);
}
