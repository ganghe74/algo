#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    string s;
    cin >> m >> n;
    while (m > 0) {
        s = "0123456789ABCDEF"[m % n] + s;
        m /= n;
    }
    if (s.empty()) cout << 0;
    else cout << s;
}