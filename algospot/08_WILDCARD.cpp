#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int cache[101][101];
string W, S;

// 완전탐색
bool match(const string& w, const string& s) {
    int pos = 0;
    while (pos < w.size() && pos < s.size() && (w[pos] == '?' || w[pos] == s[pos])) {
        ++pos;
    }
    if (pos == w.size()) return pos == s.size();
    if (w[pos] == '*') {
        for (int skip=0;pos+skip<=w.size();++skip) {
            if (match(w.substr(pos+1), s.substr(pos+skip))) return true;
        }
    }
    return false;
}

// DP O(n^3)
int matchMemoized(int w, int s) {
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }
    if (w == W.size()) return ret = (s == S.size());
    if (W[w] == '*') {
        for (int skip=0;skip+s<=S.size();++skip) {
            if (matchMemoized(w+1,s+skip)) return ret = 1;
        }
    }
    return ret = 0;
}

// DP O(n^2)
int matchMemoized2(int w, int s) {
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = matchMemoized2(w+1, s+1);
    }
    if (w == W.size()) return ret = (s == S.size());
    if (W[w] == '*') {
        if(matchMemoized2(w+1, s) || (s < S.size() && matchMemoized2(w, s+1))) return ret = 1;
    }
    return ret = 0;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        cin >> W;
        int N;
        scanf("%d", &N);
        vector<string> answers;
        while (N--) {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if(matchMemoized2(0,0)) answers.push_back(S);
        }
        sort(answers.begin(), answers.end());
        for (auto x : answers) cout << x << '\n';
    }
}