#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        map<string, int> m;
        scanf("%d", &N);
        while (N--) {
            string s;
            cin >> s >> s;
            m[s] += 1;
        }
        int ans = 1;
        for (auto p : m) ans *= p.second + 1;
        cout << ans - 1 << '\n';
    }
}