#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ans = "";
    cin >> s;
    int l, r, cnt = 0;
    if (s.size() % 2) l = r = s.size()/2;
    else l = r = s.size()/2-1;
    r++;
    bool left = true;
    while (cnt < s.size()) {
        if (left) cout << s[l--];
        else cout << s[r++];
        left = !left;
        cnt++;
    }
}