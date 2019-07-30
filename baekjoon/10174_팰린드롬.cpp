#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    if (s.size() <= 1) return true;
    return (tolower(s[0]) == tolower(s[s.size()-1])) && isPalindrome(s.substr(1, s.size()-2));
}

int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, s);
        if (isPalindrome(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}