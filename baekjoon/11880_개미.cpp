#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lint T, a, b, c;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        cout << min({a*a+(b+c)*(b+c), b*b+(a+c)*(a+c), c*c+(a+b)*e(a+b)}) << '\n';
    }
}