#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 1e+9;
map<int, int> cnt;
int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    queue<int> q;
    q.push(A);
    cnt[A] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now * 2 <= LIMIT) {
            if (!cnt[now * 2]) {
                q.push(now * 2);
                cnt[now * 2] = cnt[now] + 1;
            }
        }
        if (now < LIMIT/10) {
            if (!cnt[now * 10 + 1]) {
                q.push(now * 10 + 1);
                cnt[now * 10 + 1] = cnt[now] + 1;
            }
        }
    }
    if (cnt[B]) printf("%d", cnt[B]);
    else puts("-1");
}