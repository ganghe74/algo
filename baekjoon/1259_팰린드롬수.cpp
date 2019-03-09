#include <iostream>
using namespace std;
bool go(string s) {
    if (s.size() <= 1) return true;
    if (s.size() == 2) return s[0] == s[1];
    return s[0] == s[s.size()-1] && go(s.substr(1, s.size()-2));
}
int main() {
    string s;
    cin >> s;
    while (s != "0") {
        if (go(s)) cout << "yes\n";
        else cout << "no\n";
        cin >> s;
    }
}