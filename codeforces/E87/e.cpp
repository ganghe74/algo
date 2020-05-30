#include <bits/stdc++.h>
using namespace std;

int n, m, n1, n2, n3, u, v, COMPONENT, col[5001], cnt[10001], d[5001][5001], realcol[10001];
vector<int> a[5001];

int oppo(int n) {
    return n % 2 ? n+1 : n-1;
}

bool dfs(int u, int c) {
    cnt[c]++;
    col[u] = c;
    for (auto v : a[u]) {
        if (!col[v])
            if (dfs(v, oppo(c)) == false)
                return false;
        if (col[u] == col[v])
            return false;
    }
    return true;
}

bool solve(int num, int rem1) {
    if (num == COMPONENT)
        return !rem1;
    int &ret = d[num][rem1];
    if (ret != -1) return ret;
    int c1 = num*2+1;
    int c2 = num*2+2;
    int numc1 = cnt[c1];
    int numc2 = cnt[c2];
    if (rem1 >= numc1)
        if (solve(num+1, rem1 - numc1)) {
            realcol[c1] = 1;
            realcol[c2] = 2;
            return ret = true;
        }
    if (rem1 >= numc2) {
        if (solve(num+1, rem1 - numc2)) {
            realcol[c1] = 2;
            realcol[c2] = 1;
            return ret = true;
        }
    }
    return ret = false;
}

int main() {
    memset(d, -1 , sizeof(d));
    scanf("%d%d", &n, &m);
    scanf("%d%d%d", &n1, &n2, &n3);
    n1 += n3;
    while (m--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1;i<=n;++i) {
        if (!col[i]) {
            COMPONENT++;
            if (!dfs(i, COMPONENT*2)) {
                puts("NO");
                return 0;
            }
        }
    }
    if (!solve(0, n1)) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=1;i<=n;++i) {
        int c = realcol[col[i]];
        if (c == 1) {
            if (n3-- > 0) printf("3");
            else printf("1");
        }
        else printf("2");
    }
}
