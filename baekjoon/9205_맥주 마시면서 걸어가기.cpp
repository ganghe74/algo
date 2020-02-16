#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};

int dist(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int t, n;
Point p[102];
bool c[102];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for (int i=0;i<n+2;++i) scanf("%d%d", &p[i].x, &p[i].y);
        queue<Point> q;
        q.push(p[0]);
        c[0] = 1;

        while (!q.empty()) {
            auto now = q.front(); q.pop();
            for (int i=0;i<n+2;++i) {
                if (c[i]) continue;
                if (dist(now, p[i]) <= 1000) {
                    c[i] = 1;
                    q.push(p[i]);
                }
            }
        }
        puts(c[n+1] ? "happy" : "sad");
    }
}
