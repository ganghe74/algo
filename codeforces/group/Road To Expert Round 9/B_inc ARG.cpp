#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char s[101];
    cin >> n >> s;
    int i = 0, ans = 0;
    bool carry = 1;
    while (i < n) {
        if (carry) {
            if (s[i] == '0') carry = false;
            ans++;
        }
        else break;
        ++i;
    }
    cout << ans;
}