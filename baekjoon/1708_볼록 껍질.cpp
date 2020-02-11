#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct Point { lint x, y; };

int N;
Point p, a[100000];

int ccw(Point p1, Point p2, Point p3) {
    lint tmp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x;
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

lint dist(Point p1, Point p2) {
    lint x = p1.x - p2.x;
    lint y = p1.y - p2.y;
    return x*x + y*y;
}

bool cmp(Point u, Point v) {
    int tmp = ccw(p, u, v);
    if (tmp == 0) return dist(p, u) <= dist(p, v);
    return tmp == 1;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%lld%lld", &a[i].x, &a[i].y);
    p = a[0];
    for (int i=0;i<N;++i) {
        if (a[i].y < p.y || (a[i].y == p.y && a[i].x < p.x)) p = a[i];
    }
    sort(a, a+N, cmp);
    vector<Point> st;
    for (int i=0;i<N;++i) {
        while (st.size() >= 2 && ccw(st[st.size()-2], st[st.size()-1], a[i]) <= 0) st.pop_back();
        st.push_back(a[i]);
    }
    printf("%d", st.size());;
}
