#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};
int R, S, cnt, scnt, tcnt, dfsn[40000], sn[40000], t[100][100];
bool finished[4000];
char m[100][100];
vector<int> a[40000];
stack<int> st;

int oppo(int n) { return n%2 ? n-1 : n+1; }

int find_t(int r, int c, int k) {
    if (r < 0 || R <= r || c < 0 || S <= c) return 0;
    if (m[r][c] == '#') return 0;
    if (t[r][c]) return t[r][c];
    return find_t(r+dr[k], c+dc[k], k);
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
    scanf("%d%d", &R, &S);
    for (int i=0;i<R;++i) {
        for (int j=0;j<S;++j) {
            scanf(" %c", &m[i][j]);
            if (m[i][j] == 'T') t[i][j] = ++tcnt;
        }
    }
    for (int i=0;i<R;++i) {
        for (int j=0;j<S;++j) {
            if (m[i][j] == 'T') {
                int s = t[i][j] * 4 - 4;
                for (int k=0;k<4;++k) {
                    if (find_t(i+dr[k], j+dc[k], k)) {
                        a[s+k].push_back(oppo(s+k));
                    }
                }
            }
            else if (m[i][j] == 'n') {
                int w = find_t(i+dr[0], j+dc[0], 0);
                int e = find_t(i+dr[1], j+dc[1], 1);
                int n = find_t(i+dr[2], j+dc[2], 2);
                int s = find_t(i+dr[3], j+dc[3], 3);
                int t1, t2, k1, k2;
                if (w && e) w = e = 0;
                if (n && s) n = s = 0;
                if (n && e) t1 = n, t2 = e, k1 = 3, k2 = 0;
                else if (e && s) t1 = e, t2 = s, k1 = 0, k2 = 2;
                else if (s && w) t1 = s, t2 = w, k1 = 2, k2 = 1;
                else if (w && n) t1 = w, t2 = n, k1 = 1, k2 = 3;
                else if (n) t1 = t2 = n, k1 = k2 = 3;
                else if (e) t1 = t2 = e, k1 = k2 = 0;
                else if (s) t1 = t2 = s, k1 = k2 = 2;
                else t1 = t2 = w, k1 = k2 = 1;
                t1 = t1*4-4; t2 = t2*4-4;
                a[oppo(t1+k1)].push_back(t2+k2);
                a[oppo(t2+k2)].push_back(t1+k1);
            }
        }
    }
    for (int i=0;i<4*tcnt;++i)
        if (!dfsn[i]) dfs(i);

    int val[20000];
    memset(val, -1, sizeof(val));
    vector<pair<int,int>> p;
    for (int i=0;i<4*tcnt;++i)
        p.push_back({sn[i], i});
    sort(p.rbegin(), p.rend());
    for (auto [u, var] : p)
        if (val[var/2] == -1) val[var/2] = !(var%2);

    for (int i=0;i<R;++i) {
        for (int j=0;j<S;++j) {
            if (t[i][j]) {
                bool e = val[t[i][j]*2-2];
                bool s = val[t[i][j]*2-1];
                if (!e && s) putchar('1');
                else if (s && e) putchar('2');
                else if (e && !s) putchar('3');
                else putchar('4');
            }
            else putchar(m[i][j]);
        }
        puts("");
    }
}
