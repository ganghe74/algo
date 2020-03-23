#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i=0, j=s.size()-1;
    while (i < j)
        if (s[i++] != s[j--]) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    if (isPalindrome(s) && isPalindrome(s.substr(0, s.size()/2)) && isPalindrome(s.substr(s.size()/2+1, s.size()/2)))
        cout << "Yes";
    else
        cout << "No";
}
