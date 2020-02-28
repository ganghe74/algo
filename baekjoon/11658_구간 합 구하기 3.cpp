#include <bits/stdc++.h>
using namespace std;

int n, m, a[1025][1025], t[1025][1025];

void update(int x, int y, int val) {
    for (int i=x;i<=n;i+=i&-i)
        for (int j=y;j<=n;j+=j&-j)
            t[i][j] += val;
}

int sum(int x, int y) {
    int ans = 0;
    for (int i=x;i>0;i-=i&-i)
        for (int j=y;j>0;j-=j&-j)
            ans += t[i][j];
    return ans;
}

int main() {
    int w, x1, y1, x2, y2, c;
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) {
            scanf("%d", &a[i][j]);
            update(i, j, a[i][j]);
        }
    while (m--) {
        scanf("%d", &w);
        if (w == 0) {
            scanf("%d%d%d", &x1, &y1, &c);
            update(x1, y1, c-a[x1][y1]);
            a[x1][y1] = c;
        }
        else {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
        }
    }
}
