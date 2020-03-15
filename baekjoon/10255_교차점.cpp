#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct point {
    lint x, y;
    bool operator<(point& p) {
        if (this->x == p.x) return this->y < p.y;
        return this->x < p.x;
    }
    bool operator<=(point& p) {
        if (this->x == p.x) return this->y <= p.y;
        return this->x <= p.x;
    }
};

lint ccw(point p1, point p2, point p3) {
    lint tmp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

bool isIntersect(point p1, point p2, point p3, point p4) {
    int ab = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int cd = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (ab == 0 && cd == 0) {
        if (p2 <= p1) swap(p1, p2);
        if (p4 <= p3) swap(p3, p4);
        return p1 <= p4 && p3 <= p2;
    }
    return ab <= 0 && cd <= 0;
}

bool isOverlap(point p1, point p2, point p3, point p4) {
    if (p2 <= p1) swap(p1, p2);
    if (p4 <= p3) swap(p3, p4);
    if ((p1.x == p2.x && p2.x == p3.x && p3.x == p4.x) || (p1.y == p2.y && p2.y == p3.y && p3.y == p4.y))
        return (p1 <= p3 && p3 < p2) || (p1 < p4 && p4 <= p2) || (p3 <= p1 && p2 <= p4);
    return 0;
}

int main() {
    int T;
    point rec[4], seg[2];
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%lld%lld%lld%lld", &rec[0].x, &rec[0].y, &rec[2].x, &rec[2].y);
        scanf("%lld%lld%lld%lld", &seg[0].x, &seg[0].y, &seg[1].x, &seg[1].y);
        if (seg[1] < seg[0]) swap(seg[0], seg[1]);
        rec[1].x = rec[2].x;
        rec[1].y = rec[0].y;
        rec[3].x = rec[0].x;
        rec[3].y = rec[2].y;
        for (int i=0;i<4;++i) {
            if (isIntersect(rec[i], rec[(i+1)%4], seg[0], seg[1])) cnt++;
            if (isOverlap(rec[i], rec[(i+1)%4], seg[0], seg[1])) cnt=10;
        }
        for (int i=0;i<4;++i)
            if (!ccw(seg[0], seg[1], rec[i]))
                if (seg[0] <= rec[i] && rec[i] <= seg[1]) cnt--;
        printf("%d\n", min(cnt, 4));
    }
}
