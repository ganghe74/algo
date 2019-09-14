#include <bits/stdc++.h>
using namespace std;
int group[26];
int main() {
    int N1, N2, T;
    string s, ans;
    cin >> N1 >> N2;
    cin >> s;
    reverse(s.begin(), s.end());
    ans = s;
    for (char x : s) group[x-'A'] = 1;
    cin >> s;
    ans += s;
    for (char x : s) group[x-'A'] = 2;
    cin >> T;
    while (T--) {
        for (int i=0;i<ans.size()-1;++i) {
            if (group[ans[i]-'A'] == 1 && group[ans[i+1]-'A'] == 2) {
                swap(ans[i], ans[i+1]);
                ++i;
            }
        }
    }
    cout << ans << endl;
}