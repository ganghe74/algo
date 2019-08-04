#include <bits/stdc++.h>
using namespace std;

int d[200001];

int main() {
    int N, K, cnt = 0;
    scanf("%d%d", &N, &K);

    queue<int> q;
    q.push(N);
    d[N] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == K) cnt++;
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= 200000) {
                if (!d[next] || d[next] == d[now]+1) {
                    d[next] = d[now]+1;
                    q.push(next);
                }
            }
        }
    }

    printf("%d\n%d", d[K]-1, cnt);
}