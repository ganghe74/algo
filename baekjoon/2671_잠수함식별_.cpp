#include <bits/stdc++.h>
using namespace std;

int main() {
    regex re("(100+1+|01)+");
    cmatch m;
    string s;
    cin >> s;
    bool ans = regex_match(s.c_str(), m, re);
    cout << (ans ? "SUBMARINE" : "NOISE") << '\n';
}
