#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
bool operator<=(point p1, point p2) {
    if (p1.x == p2.x) return p1.y <= p2.y;
    return p1.x <= p2.x;
}
struct line {
    point p1, p2;
};
int ccw(point p1, point p2, point p3) {
    int ret = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    ret -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
}
bool check(line l1, line l2) {
    point p1 = l1.p1, p2 = l1.p2, p3 = l2.p1, p4 = l2.p2;
    int line1_2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int line2_1 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (line1_2 == 0 && line2_1 == 0) {
        if (p2 <= p1) swap(p1, p2);
        if (p4 <= p3) swap(p3, p4);
        return p1 <= p4 && p3 <= p2;
    }
    return line1_2 <= 0 && line2_1 <= 0;
}

line a[3000];
int parent[3000], w[3000];
bool c[3000];

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
    w[y] += w[x];
    w[x] = 0;
}

int main() {
    for (int i=0;i<3000;++i) {
        parent[i] = i;
        w[i] = 1;
    }
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[i] = {x1, y1, x2, y2};
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<i;++j) {
            if (check(a[i], a[j])) {
                if (Find(i) != Find(j)) Union(i, j);
            }
        }
    }
    int cnt = 0, M = 0;
    for (int i=0;i<N;++i) {
        int f = Find(i);
        if (!c[f]) {
            c[f] = 1;
            cnt++;
            M = max(M, w[f]);
        }
    }
    printf("%d\n%d", cnt, M);
}