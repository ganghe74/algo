#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(string &N) {
    int m = N.size();
    vector<int> pi(m);
    for (int i=1,j=0;i<m;++i) {
        while (j && N[i] != N[j]) j = pi[j-1];
        if (N[i] == N[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> kmpSearch(string &H, string &N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    for (int i=0,j=0;i<n;++i) {
        while (j && H[i] != N[j]) j = pi[j-1];
        if (H[i] == N[j]) {
            if (j == m-1) {
                ret.push_back(i-m+1);
                j = pi[j];
            }
            else j++;
        }
    }
    return ret;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << ((kmpSearch(a, c).size() && kmpSearch(b, c).size()) ? "YES" : "NO") << endl;
}
