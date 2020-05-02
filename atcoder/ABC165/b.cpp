#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint x;
    cin >> x;
    lint money = 100;
    lint cnt = 0;
    while (money < x) {
        money += money / 100;
        cnt++;
    }

    cout << cnt;
}
