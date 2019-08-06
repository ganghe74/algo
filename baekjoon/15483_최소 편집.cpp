#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i=0;i<=s1.size();++i) d[i][0] = i;
    for (int i=0;i<=s2.size();++i) d[0][i] = i;
    for (int i=1;i<=s1.size();++i) {
        for (int j=1;j<=s2.size();++j) {
            if (s1[i-1] == s2[j-1]) d[i][j] = d[i-1][j-1];
            else d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1;
        }
    }
    printf("%d", d[s1.size()][s2.size()]);
}