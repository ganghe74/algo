#include <bits/stdc++.h>
using namespace std;

int main() {
    int L;
    string s;
    cin >> L >> s;
    int begin = 1, matched = 0;
    vector<int> pi(L);
    while (begin + matched < L) {
        if (s[matched] == s[begin + matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    cout << L - pi[L-1];
}