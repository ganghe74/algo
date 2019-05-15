#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, ans = 0;
    cin >> a >> b;
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        ans += a / b;
        a %= b;
    }
    cout << ans;
}