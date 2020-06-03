#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint n;
    cin >> n;
    n %= 7;
    if (n == 0 || n == 2) cout << "CY";
    else cout << "SK";
}
