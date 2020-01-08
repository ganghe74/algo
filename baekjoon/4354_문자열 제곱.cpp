#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    while (true) {
        getline(cin, s);
        if (s == ".") break;
        int N = s.size();
        vector<int> pi(N);
        for (int i=1,j=0;i<N;++i) {
            while (j && s[i] != s[j]) j = pi[j-1];
            if (s[i] == s[j]) pi[i] = ++j;
        }
        int x = pi[N-1];
        if (N % (N-x) == 0) cout << N / (N-x) << '\n';
        else cout << "1\n";
    }
}