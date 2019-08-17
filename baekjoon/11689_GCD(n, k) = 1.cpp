#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint n, q, ans;
vector<lint> factors;
bool c[12];

void choice(int idx) {
    lint gcd = 1, cnt = 0;
    for (int i=0;i<factors.size();++i) {
        if (c[i]) {
            gcd *= factors[i];
            cnt++;
        }
    }
    if (cnt > 0) {
        if (cnt % 2) ans -= n / gcd;
        else ans += n / gcd;
    }
    for (int i=idx;i<factors.size();++i) {
        c[i] = 1;
        choice(i+1);
        c[i] = 0;
    }
}


int main() {
    cin >> n;
    ans = q = n;
    lint i = 2;
    lint q = n;
    while (q > 1 && i*i <= n) {
        if (q % i == 0) factors.push_back(i);
        while (q % i == 0) {
            q /= i;
        }
        i++;
    }
    if (q != 1) factors.push_back(q);
    choice(0);
    printf("%lld", ans);
}