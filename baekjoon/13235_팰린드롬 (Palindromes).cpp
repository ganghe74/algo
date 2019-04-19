#include <iostream>
#include <string>
using namespace std;

bool solve(string s) {
    if (s.size() == 1) return true;
    if (s.size() == 2) return s[0] == s[1];
    return (s[0] == s[s.size()-1]) && solve(s.substr(1,s.size()-2));
}

int main() {
    string s;
    cin >> s;
    if (solve(s)) cout << "true";
    else cout << "false";
}