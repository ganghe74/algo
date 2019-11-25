#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s == "*") break;
        bool flag = true;
        char c = tolower(s[0]);
        for (int i=0;i<s.size();++i) {
            if (s[i] == ' ') {
                if (tolower(s[i+1]) != c) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? 'Y' : 'N') << endl;
    }
}