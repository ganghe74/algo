#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint n, x;
    cin >> n >> x;
    if (n > 5) cout << "Love is open door";
    else {
        for (int i=2;i<=n;++i) cout << (i+x-1)%2 << '\n';
    }
}