#include <bits/stdc++.h>
using namespace std;
int main() {
    int S, K;
    cin >> S >> K;
    vector<int> a(K, S/K);
    for (int i=0;i<S-S/K*K;++i) a[i]++;
    long long ans = 1;
    for (auto n : a) ans *= n;
    cout << ans;
}