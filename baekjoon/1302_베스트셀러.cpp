#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    map<string, int> m;
    while (N--) {
        string s;
        cin >> s;
        m[s]++;
    }
    pair<string, int> ans;
    for (auto pi : m) {
        if (ans.second < pi.second) ans = pi;
    }
    cout << ans.first;
}