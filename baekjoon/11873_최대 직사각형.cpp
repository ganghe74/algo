#include <bits/stdc++.h>
using namespace std;

int N, M, ans, a[1000][1000], h[1000][1000], l[1000], r[1000];
int main() {
    while (true) {
        scanf("%d%d", &N, &M);
        if (!N && !M) break;
        for (int i=0;i<N;++i) {
            for (int j=0;j<M;++j) {
                scanf("%d", &a[i][j]);
                if (!i) h[i][j] = a[i][j];
                else if (a[i][j]) h[i][j] = h[i-1][j] + 1;
                else h[i][j] = 0;
            }
        }
        ans = 0;
        for (int H=0;H<N;++H) {
            stack<pair<int,int>> st;
            for (int i=0;i<M;++i) {
                while (!st.empty() && st.top().first >= h[H][i]) st.pop();
                l[i] = st.empty() ? -1 : st.top().second;
                st.push({h[H][i], i});
            }
            st = {};
            for (int i=M-1;i>=0;--i) {
                while (!st.empty() && st.top().first >= h[H][i]) st.pop();
                r[i] = st.empty() ? M : st.top().second;
                st.push({h[H][i], i});
            }
            for (int i=0;i<M;++i) ans = max(ans, (r[i] - l[i] - 1) * h[H][i]);
        }
        printf("%d\n", ans);
    }
}
