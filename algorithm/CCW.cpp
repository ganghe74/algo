// https://www.acmicpc.net/problem/11758
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct Point {
    lint x, y;
};

int ccw(Point p1, Point p2, Point p3) {
    int tmp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

int main() {
    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << ccw(p1, p2, p3);
}
