#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> m;
    string name;
    int N, sum = 0, ans = 0;
    cin >> N;
    while (N--) {
        cin >> name;
        if (m[name] > sum - m[name]) ans++;
        m[name]++;
        sum++;
    }
    cout << ans;
}