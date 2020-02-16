#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, y;
    vector<pair<int,int>> a;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &x, &y);
        a.push_back({x, 1});
        a.push_back({y, -1});
    }
    sort(a.begin(), a.end());
    int ans = 0, cnt = 0, start = 0;
    for (auto pi : a) {
        cnt += pi.second;
        if (pi.second == 1 && cnt == 1) start = pi.first;
        if (pi.second == -1 && cnt == 0) ans += pi.first - start;
    }
    printf("%d", ans);
}
