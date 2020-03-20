#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(const string &N) {
    int m = N.size();
    vector<int> pi(m, 0);
    for (int i=1,j=0;i<m;++i) {
        while (j && N[i] != N[j]) j = pi[j-1];
        if (N[i] == N[j]) pi[i] = ++j;
    }
    return pi;
}

bool isPalindrome(string s) {
    int i=0, j=s.size()-1;
    while (i < j)
        if (s[i++] != s[j--]) return false;
    return true;
}

string solve(string s) {
    if (s == "") return "";
    if (s.size() == 1) return s;
    if (s.size() == 2 && s.front() == s.back()) return s;
    int LenTrimed = 0;
    while (LenTrimed < int(s.size()/2) && s[LenTrimed] == s[s.size()-1-LenTrimed]) LenTrimed++;


    string ss = string(s.begin() + LenTrimed, s.begin() + LenTrimed + (s.size() - LenTrimed*2));

    string sr = string(ss.rbegin(), ss.rend());
    string t1 = ss + '#' + sr;
    int LenPrefix = getPartialMatch(t1).back();

    string t2 = sr + '#' + ss;
    int LenSuffix = getPartialMatch(t2).back();

    string S;

    if (LenPrefix > LenSuffix) S = ss.substr(0,LenPrefix);
    else S = ss.substr(ss.size()-LenSuffix, LenSuffix);

    return s.substr(0, LenTrimed) + S + s.substr(s.size() -  LenTrimed, LenTrimed);
}

int t;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        cout << solve(s) << '\n';
    }
}
