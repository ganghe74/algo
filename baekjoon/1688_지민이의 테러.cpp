#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct Point {
    lint x, y;
};
struct Line {
    Point p1, p2;
};

int N, M = 3;
Point a[10001];

int ccw(Point p1, Point p2, Point p3) {
    lint tmp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

bool cross(Line l1, Line l2) {
    int a = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int b = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
    return a < 0 && b < 0;
}

bool go(Point p) {
    for (int i=0;i<N;++i) {
        int tmp = ccw(p, a[i], a[i+1]);
        if (!tmp) {
            int minx = min(a[i].x, a[i+1].x);
            int maxx = max(a[i].x, a[i+1].x);
            int miny = min(a[i].y, a[i+1].y);
            int maxy = max(a[i].y, a[i+1].y);
            if (minx <= p.x && p.x <= maxx && miny <= p.y && p.y <= maxy) return 1;
        }
    }
    int cnt = 0;
    Point out = {1, 2147483647};
    for (int i=0;i<N;++i) {
        cnt += cross({p, out}, {a[i], a[i+1]});
    }
    return cnt % 2;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%lld%lld", &a[i].x, &a[i].y);
    a[N] = a[0];
    while (M--) {
        Point p;
        scanf("%lld%lld", &p.x, &p.y);
        printf("%d\n", go(p));
    }
}
