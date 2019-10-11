#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint n, w, before, now;
    cin >> n >> w >> before;
    while (--n) {
        cin >> now;
        if (now > before) w = w - w / before * before + w / before * now;
        before = now;
    }
    cout << w;
}