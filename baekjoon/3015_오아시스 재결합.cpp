#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 0;
    int n, h;
    scanf("%d", &n);
    stack<pair<int,int>> s;
    for (int i=0;i<n;++i) {
        scanf("%d", &h);
        pair<int,int> p = {h, 1};
        while (!s.empty()) {
            if (s.top().first <= h) {
                ans += (long long)s.top().second;
                if (s.top().first == h) {
                    p.second += s.top().second;
                }
                s.pop();
            }
            else break;
        }
        if (!s.empty()) ans += 1;
        s.push(p);
    }
    printf("%lld", ans);
}