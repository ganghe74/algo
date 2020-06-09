//TODO
//
// Euclidean Distance, CCW, Line Intersection, Convex Hull, Rotating Calipers...
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct Point {
    lint x, y;
    bool operator<(Point p) {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    Point operator-() {
        return {-x, -y};
    }
    Point operator-(Point p) {
        return {x-p.x, y-p.y};
    }
};

lint ccw(Point p1, Point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

lint ccw(Point p1, Point p2, Point p3) {
    return p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x;
}

lint dist2(Point p1, Point p2) {
    lint x = p1.x-p2.x;
    lint y = p1.y-p2.y;
    return x*x + y*y;
}

// Convex Hull
// Parameter: Points
// Return Convex Hull, first element is bottom-leftmost, ccw.

// Graham Scan O(NlogN)
vector<Point> convexHull1(vector<Point> &a) {
    swap(a[0], *min_element(a.begin(), a.end()));
    sort(a.begin()+1, a.end(), [&](Point p1, Point p2) {
        int t = ccw(a[0], p1, p2);
        if (!t) return dist2(a[0], p1) < dist2(a[0], p2);
        return t > 0;
    });
    vector<Point> st;
    for (auto &p : a) {
        while (st.size() >= 2 && ccw(st[st.size()-2], st.back(), p) <= 0) st.pop_back();
        st.push_back(p);
    }
    return st;
}

// Monotone Chain O(NlogN)
vector<Point> convexHull2(vector<Point> &a) {
    sort(a.begin(), a.end());
    vector<Point> u, d;
    for (auto &p : a) {
        while (u.size() >= 2 && ccw(u[u.size()-2], u.back(), p) >= 0) u.pop_back();
        while (d.size() >= 2 && ccw(d[d.size()-2], d.back(), p) <= 0) d.pop_back();
        u.push_back(p); d.push_back(p);
    }
    d.insert(d.end(), u.rbegin()+1, u.rend()-1);
    return d;
}

// Rotating Calipers
// Parameter: Convex Hull
// Return Diameter of Convex Hull (farthest two points)
// For convenience, return square of diameter.
// TODO
// I can't prove the correctness of this algorithm...

lint diameter1(vector<Point> &p) {
    int n = p.size();
    int l = min_element(p.begin(), p.end()) - p.begin();
    int r = max_element(p.begin(), p.end()) - p.begin();
    lint MAX = dist2(p[l], p[r]);
    vector<Point> toNext(n);
    for (int i=0;i<n;++i)
        toNext[i] = p[(i+1)%n] - p[i];
    int a = l, b = r;
    while (a != r || b != l) {
        if (ccw(toNext[a], toNext[b]) <= 0) a = (a+1)%n;
        else b = (b+1)%n;
        MAX = max(MAX, dist2(p[a], p[b]));
        if (a == l && b == r) break;
    }
    return MAX;
}

// https://codeforces.com/blog/entry/48868
lint diameter2(vector<Point> &a) {
    int n = a.size();
    lint MAX = 0;
    for (int i=0,j=1;i<j;++i)
        for (;;j=(j+1)%n) {
            MAX = max(MAX, dist2(a[i], a[j]));
            if (ccw(a[i+1]-a[i], a[(j+1)%n]-a[j]) <= 0) break;
        }
    return MAX;
}
