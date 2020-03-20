#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MOD = 998244353;

int n, k, x;
lint numOfCase, val;

vector<pair<int,int>> p;

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        p.push_back({x, i});
    }
    sort(p.rbegin(), p.rend());
    vector<int> pos;
    for (int i=0;i<k;++i) {
        pos.push_back(p[i].second);
        val += p[i].first;
    }
    sort(pos.begin(), pos.end());

    numOfCase = 1;
    for (int i=1;i<k;++i)
        numOfCase = (numOfCase * (pos[i]-pos[i-1])) % MOD;

    printf("%lld %lld", val, numOfCase);
}
