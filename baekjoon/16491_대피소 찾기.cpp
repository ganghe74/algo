#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    bool operator<=(point& p) {
        if (this->x == p.x) return this->y <= p.y;
        return this->x <= p.x;
    }
};

int ccw(point p1, point p2, point p3) {
    int tmp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
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

int main() {
    int N;
    point robot[10], shelter[10];
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d%d", &robot[i].x, &robot[i].y);
    for (int i=0;i<N;++i) scanf("%d%d", &shelter[i].x, &shelter[i].y);
    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 0);
    do {
        vector<pair<point,point>> segs;
        for (int i=0;i<N;++i)
            segs.push_back({robot[i], shelter[perm[i]]});
        bool ok = true;
        for (int i=0;i<N;++i) {
            for (int j=i+1;j<N;++j) {
                if (isIntersect(segs[i].first, segs[i].second, segs[j].first, segs[j].second))
                    ok = false;
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (ok) {
            for (int x : perm) printf("%d\n", x+1);
            break;
        }
    } while(next_permutation(perm.begin(), perm.end()));
}
