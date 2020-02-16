#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
    bool operator < (const Point &p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}

int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int main() {
    int n;
    Point a[100000];
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a, a+n, cmp);
    set<Point> s = {a[0], a[1]};
    int ans = dist(a[0], a[1]);
    int start = 0;
    for (int i=2;i<n;++i) {
        Point now = a[i];
        while (start < i) {
            auto p = a[start];
            int x = now.x - p.x;
            if (x*x > ans) {
                s.erase(p);
                start++;
            }
            else {
                break;
            }
        }
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = Point({-100000, now.y-d});
        auto upper_point = Point({100000, now.y+d});
        auto lower = s.lower_bound(lower_point);
        auto upper = s.upper_bound(upper_point);
        for (auto it = lower; it != upper; it++) {
            int d = dist(now, *it);
            ans = min(ans, d);
        }
        s.insert(now);
    }
    printf("%d", ans);
}
