#include <bits/stdc++.h>
using namespace std;

char change(char x) {
    if (!isalpha(x)) return x;
    if (x <= 'Z') return x + 32;
    return x - 32;
}

int main() {
    int YAY = 0, WHOOPS = 0;
    string s, t;
    cin >> s >> t;
    map<char, int> m;
    for (char x : t) m[x]++;
    for (char &x : s) {
        if (m[x] > 0) {
            YAY++;
            m[x]--;
            x = '-';
        }
    }
    for (char x : s) {
        x = change(x);
        if (m[x] > 0) {
            WHOOPS++;
            m[x]--;
        }
    }
    cout << YAY << ' ' << WHOOPS;
}