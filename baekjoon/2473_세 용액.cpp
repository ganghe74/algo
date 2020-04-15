#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
vector<lint> a;

int main() {
    scanf("%d", &N);
    a.resize(N);
    for (int i=0;i<N;++i) scanf("%lld", &a[i]);
    a.push_back(-1e15);
    a.push_back(1e15);
    sort(a.begin(), a.end());

    vector<lint> ans = {a[0], a[1], a[2]};
    lint diff = 1e18;

    for (int i=2;i<N;++i) {
        for (int j=1;j<i;++j) {
            lint ph = a[i]+a[j];
            auto it = lower_bound(a.begin()+i+1, a.end(), -ph);
            if (it == a.end()) printf("it is end\n");
            if (*it != a[i] && *it != a[j] && abs(*it+ph) < diff) {
                ans = {a[i], a[j], *it};
                diff = abs(*it+ph);
            }
            --it;
            if (*it != a[i] && *it != a[j] && abs(*it+ph) < diff) {
                ans = {a[i], a[j], *it};
                diff = abs(*it+ph);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (lint x : ans) printf("%lld ", x);
}
