#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, x, y, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<pair<int,int>> points;
        points.push_back({-1, 0});
        for (int i=0;i<n;++i) {
            scanf("%d%d", &x, &y);
            points.push_back({x, y});
        }
        sort(points.begin(), points.end());

        for (int i=1;i<points.size();++i) {
            if (points[i].first != points[i-1].first && points[i].second != points[i-1].second) {
                auto ed = lower_bound(points.begin(), points.end(), make_pair(points[i].first+1, (int)-1e9));
                reverse(points.begin()+i, ed);
            }
        }

        scanf("%d", &m);
        while (m--) {
            scanf("%d", &n);
            printf("%d %d\n", points[n].first, points[n].second);
        }
    }
}