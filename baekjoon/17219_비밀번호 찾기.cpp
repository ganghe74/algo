#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;
    string url, passwd;
    map<string, string> m;
    cin >> N >> M;
    while (N--) {
        cin >> url >> passwd;
        m[url] = passwd;
    }
    while (M--) {
        cin >> url;
        cout << m[url] << '\n';
    }
}
