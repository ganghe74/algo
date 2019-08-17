#include <bits/stdc++.h>
using namespace std;

priority_queue<int> a[5][5];

int convert(char x) {
    return (x - 60) / 6;
}

int solve(int now) {
    int ret = 0;
    for (int next=0;next<5;++next) {
        if (!a[now][next].empty()) {
            int w = a[now][next].top(); a[now][next].pop();
            ret = max(ret, w + solve(next));
            a[now][next].push(w);
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    for (int i=0;i<N;++i) {
        string s;
        cin >> s;
        int u = convert(s[0]), v = convert(s.back()), w = s.size();
        a[u][v].push(w);
    }
    int ans = 0;
    for (int i=0;i<5;++i) ans = max(ans, solve(i));
    cout << ans;
}