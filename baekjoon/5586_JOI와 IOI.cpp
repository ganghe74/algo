#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int joi = 0, ioi = 0;
    string s;
    cin >> s;
    for (int i=0;i<s.size()-2;++i) {
        if (s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I') joi++;
        if (s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') ioi++;
    }
    cout << joi << '\n' << ioi;
}