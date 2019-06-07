#include <bits/stdc++.h>
using namespace std;
int a[100000], l[100000], r[100000];
int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i=0;i<n;++i) scanf("%d", &a[i]);
        stack<pair<int,int>> st;
        for (int i=0;i<n;++i) {
            while (!st.empty() && st.top().first >= a[i]) st.pop();
            l[i] = (st.empty()) ? -1 : st.top().second;
            st.push({a[i], i});
        }
        st = {};
        for (int i=n-1;i>=0;--i) {
            while (!st.empty() && st.top().first >= a[i]) st.pop();
            r[i] = (st.empty()) ? n : st.top().second;
            st.push({a[i], i});
        }
        long long ans = 0;
        for (int i=0;i<n;++i) {
            ans = max(ans, 1LL * (r[i] - l[i] - 1) * a[i]);
        }
        printf("%lld\n", ans);
    }
}