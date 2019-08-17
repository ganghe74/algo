#include <bits/stdc++.h>
using namespace std;

int f(string s1, string s2) {
    int p = 1;
    int a[4] = {0};
    for (char x : s1+s2) {
        if (x == 'L') a[0]++;
        if (x == 'O') a[1]++;
        if (x == 'V') a[2]++;
        if (x == 'E') a[3]++;
    }
    for (int i=0;i<4;++i) {
        for (int j=0;j<i;++j) p *= a[i]+a[j];
    }
    return p % 100;
}

int main() {
    string guy;
    cin >> guy;
    int N;
    cin >> N;
    vector<string> girls(N);
    for (int i=0;i<N;++i) cin >> girls[i];
    sort(girls.begin(), girls.end());

    int maxP = -1;
    string ans;
    for (string girl : girls) {
        int p = f(guy, girl);
        if (p > maxP) {
            maxP = p;
            ans = girl;
        }
    }
    cout << ans;
}