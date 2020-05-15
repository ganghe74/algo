#include <bits/stdc++.h>
using namespace std;

int t, n, k, f[1000001];
bool c[1000001];


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i=2;i<=1000000;++i) {
        if (!c[i]) {
            f[i] = i;
            for (int j=2;i*j<=1000000;++j) {
                c[i*j] = 1;
                if (!f[i*j]) f[i*j] = i;
            }
        }
    }

    cin >> t;
    while (t--) {
        cin >> n >> k;
        while (k--) {
            if (n % 2 == 0) {
                n += 2 * (k+1);
                break;
            }
            else n += f[n];
        }
        cout << n << '\n';
    }
}
