#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a,b);
}
int main() {
    ll g, l, a, b;
    cin >> g >> l;
    a = b = l;
    for (ll i=g;i<l;++i) {
        if (g * l % i == 0) {
            ll aa = i;
            ll bb = g * l / i;
            if (gcd(aa, bb) == g && lcm(aa, bb) == l) {
                if (aa + bb < a + b) {
                    a = aa;
                    b = bb;
                }
            }
        }
    }
    cout << a << ' ' << b;
}