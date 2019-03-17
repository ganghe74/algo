#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int T, N, K, X, Y, W;
    scanf("%d", &T);
    while (T--) {
        int d[1001], pre[1001] = {0}, ans[1001] = {0};
        vector<int> a[1001];
        scanf("%d%d", &N, &K);
        for (int i=1;i<=N;++i) scanf("%d", &d[i]);
        while(K--) {
            scanf("%d%d", &X, &Y);
            a[X].push_back(Y);
            pre[Y]++;
        }
        scanf("%d", &W);
        queue<int> Q;
        for (int i=1;i<=N;++i) {
            if (!pre[i]) Q.push(i);
        }
        while (pre[W]) {
            int now = Q.front();
            for (int next : a[now]) {
                ans[next] = max(ans[next], ans[now]+d[now]);
                pre[next]--;
                if (!pre[next]) Q.push(next);
            }
            Q.pop();
        }
        printf("%d\n", ans[W]+d[W]);
    }
}