#include <bits/stdc++.h>
using namespace std;
bool prime[5000001];
vector<int> d[5000001];

vector<int> solve(int x) {
    if (!prime[x]) return d[x];
    vector<int>& ret = d[x];
    if (!ret.empty()) return ret;
    int mod = 2;
    while (true) {
        if (x%mod == 0) {
            ret.push_back(mod);
            for (int n : solve(x/mod)) {
                ret.push_back(n);
            }
            break;
        }
        ++mod;
    }
    return ret;
}

int main() {
    for (int i=2;i<=5000000;++i) {
        if (!prime[i]) {
            d[i].push_back(i);
            for (int j=2;i*j<=5000000;++j) {
                prime[i*j] = true;
            }
        }
    }

    int N, k;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &k);
        for (int n : solve(k)) printf("%d ", n);
        printf("\n");
    }
}