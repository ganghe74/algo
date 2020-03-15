#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point operator-(Point &p) {
        return {this->x - p.x, this->y - p.y};
    }

};
using Vector = Point;

int n, m;
Point A[2000][2], B[2000][2];

double dist(Point a, Point b) {
    return hypot(a.x-b.x, a.y-b.y);
}

double dot(Vector a, Vector b) {
    return a.x*b.x + a.y*b.y;
}

double cross(Vector a, Vector b) {
    return a.x*b.y - b.x*a.y;
}

double H(Point a, Point b, Point c) {
    double co1 = dot(b-a, c-a);
    double co2 = dot(a-b, c-b);
    if (co1 * co2 >= 0)
        return abs(cross(b-a, c-a)) / dist(a, b);
    return 1e9;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;++i)
        scanf("%lf%lf%lf%lf", &A[i][0].x, &A[i][0].y, &A[i][1].x, &A[i][1].y);
    for (int i=0;i<m;++i)
        scanf("%lf%lf%lf%lf", &B[i][0].x, &B[i][0].y, &B[i][1].x, &B[i][1].y);
    double ans = 1e9;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            for (int k=0;k<2;++k)
                for (int l=0;l<2;++l)
                    ans = min(ans, dist(A[i][k], B[j][l]));
            for (int k=0;k<2;++k)
                ans = min(ans, H(A[i][0], A[i][1], B[j][k]));
            for (int k=0;k<2;++k)
                ans = min(ans, H(B[j][0], B[j][1], A[i][k]));
        }
    }
    printf("%.16lf", ans);
}
