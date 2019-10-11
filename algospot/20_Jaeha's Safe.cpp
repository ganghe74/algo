#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string &N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (matched == m) ret.push_back(begin);
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int shifts(const string& original, const string& target) {
    return kmpSearch(original+original, target)[0];
}

int main() {
    int C, N;
    cin >> C;
    while (C--) {
        cin >> N;
        int ans = 0;
        string before, next;
        cin >> before;
        for (int i=0;i<N;++i) {
            cin >> next;
            if (i % 2 == 0) ans += shifts(next, before);
            else ans += shifts(before, next);
            before = next;
        }
        cout << ans << endl;
    }
}