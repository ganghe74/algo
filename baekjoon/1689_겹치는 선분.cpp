#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, y, cnt = 0, ans = 0;
    vector<pair<int,int>> a;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &x, &y);
        a.push_back({x, 1});
        a.push_back({y, -1});
    }
    sort(a.begin(), a.end());
    for (auto pi : a) {
        cnt += pi.second;
        ans = max(ans, cnt);
    }
    printf("%d", ans);
}
