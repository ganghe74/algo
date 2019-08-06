#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2) {
    for (int i=0;i<s1.size();++i) {
        if (s1[i] != '*' && s1[i] != s2[i]) return false;
    }
    return true;
}

int main() {
    vector<string> ans;
    int N;
    string s1, s2;
    cin >> s1 >> N;
    while (N--) {
        cin >> s2;
        if (check(s1, s2)) {
            ans.push_back(s2);
        }
    }
    cout << ans.size() << '\n';
    for (string s : ans) cout << s << '\n';
}