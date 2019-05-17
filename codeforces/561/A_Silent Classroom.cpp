#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int main() {
    int n, ans = 0;
    string name;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> name;
        cnt[name[0]-'a']++;
    }
    for (int i=0;i<26;++i) {
        int a = cnt[i] / 2;
        int b = cnt[i] - a;
        ans += a * (a-1) / 2 + b * (b-1) / 2;
    }
    cout << ans;
}