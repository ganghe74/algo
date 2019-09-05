#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint a, b;
    cin >> a >> b;
    a--;
    if (a < 3) a = 3;
    if (b < 4) b = a;
    cout << b/2*(b/2*2+2)/2 - a/2*(a/2*2+2)/2;
}