#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> a;
bool no[100];
int N;

bool solve(int idx) {
    if (idx == s.size()) return true;
    if (no[idx]) return false;
    for (int i=0;i<N;++i) {
        if (idx + a[i].size() - 1 <= s.size()) {
            if (s.substr(idx, a[i].size()) == a[i]) {
                if (solve(idx + a[i].size())) return true;
            }
        }
    }
    no[idx] = 1;
    return false;
}

int main() {
    cin >> s >> N;
    a.resize(N);
    for (int i=0;i<N;++i) cin >> a[i];
    cout << solve(0);
}