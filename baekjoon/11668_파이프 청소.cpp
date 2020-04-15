#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<=(Point &p) {
        if (this->x == p.x) return this->y <= p.y;
        return this->x <= p.y;
    }
};

int w, p, x, y, u, v, cnt, scnt, dfsn[2000], sn[2000], psrc[1000];
bool finished[2000];
vector<int> a[2000];
stack<int> st;
Point src[1000], pipe[1000][2];

int oppo(int n) { return n%2 ? n-1 : n+1; }

int ccw(Point p1, Point p2, Point p3) {
    int tmp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4) {
    int ab = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int cd = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (ab == 0 && cd == 0) {
        if (p2 <= p1) swap(p1, p2);
        if (p4 <= p3) swap(p3, p4);
        return p1 <= p4 && p3 <= p2;
    }
    return ab <= 0 && cd <= 0;
}

int dfs(int u) {
    int ret = dfsn[u] = ++cnt;
    st.push(u);
    for (int v : a[u]) {
        if (!dfsn[v]) ret = min(ret, dfs(v));
        else if (!finished[v]) ret = min(ret, dfsn[v]);
    }
    if (ret == dfsn[u]) {
        scnt++;
        while (true) {
            int t = st.top(); st.pop();
            finished[t] = 1;
            sn[t] = scnt;
            if (t == u) break;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &w, &p);
    for (int i=0;i<w;++i) {
        scanf("%d%d", &x, &y);
        src[i] = {x, y};
    }
    for (int i=0;i<p;++i) {
        scanf("%d%d%d", &u, &x, &y);
        u--;
        psrc[i] = u;
        pipe[i][0] = src[u];
        pipe[i][1] = {x, y};
        for (int j=0;j<i;++j) {
            if (psrc[i] == psrc[j]) continue;
            if (isIntersect(pipe[i][0], pipe[i][1], pipe[j][0], pipe[j][1])) {
                u = i*2+1;
                v = j*2+1;
                a[u].push_back(oppo(v));
                a[v].push_back(oppo(u));
                a[oppo(u)].push_back(v);
                a[oppo(v)].push_back(u);
            }
        }
    }
    for (int i=0;i<2*p;++i)
        if (!dfsn[i]) dfs(i);
    for (int i=0;i<p;++i) {
        if (sn[i*2] == sn[i*2+1]) {
            puts("impossible");
            return 0;
        }
    }
    puts("possible");
}
