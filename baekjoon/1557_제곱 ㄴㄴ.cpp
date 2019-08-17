#include <bits/stdc++.h>
using namespace std;
using lint = long long;

bool c[45000];
vector<int> p;
lint n, th;

void choice(int idx, int cnt, lint s) { // n is ?th nononum?
    if (cnt % 2) th -= n / s;
    else th += n / s;
    for (int i=idx;i<p.size();++i) {
        if (s * p[i]*p[i] > n) break;
        choice(i+1, cnt+1, s*p[i]*p[i]);
    }
}

int main() {
    for (int i=2;i<45000;++i) {
        if (!c[i]) {
            p.push_back(i);
            for (int j=2;i*j<45000;++j) c[i*j] = 1;
        }
    }
    int k;
    scanf("%d", &k);
    lint l = 0, r = 2e9;
    while (l <= r) {
        n = (l+r) / 2;
        th = 0;
        choice(0,0,1);
        if (th >= k) r = n - 1;
        else l = n + 1;
    }
    printf("%lld", l);
}