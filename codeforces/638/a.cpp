#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint ans, sumall, suma;
lint a[30];

void choose(int n, int r, int idx) {
    if (r == 0) {
        ans = min(ans, abs(sumall-suma));
        return;
    }
    for (int i=idx;i<n;++i) {
        suma += a[i];
        choose(n, r-1, i+1);
        suma -= a[i];
    }
}

int main() {
    a[0] = 2;
    for (int i=1;i<30;++i) a[i] = a[i-1] * 2;
    lint t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = INT64_MAX;
        suma = 0;
        sumall = 0;
        for (int i=0;i<n;++i) sumall += a[i];
        choose(n, n/2, 0);
        cout << ans << endl;
    }
}
