#include <bits/stdc++.h>
using namespace std;

int d[200001], before[200001];

void f(int x) {
    if (before[x] == x) return;
    f(before[x]);
    printf("%d ", x);
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    queue<int> q;
    q.push(N);
    d[N] = 1;
    before[N] = N;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= 200000) {
                if (!d[next]) {
                    q.push(next);
                    d[next] = d[now] + 1;
                    before[next] = now;
                }
            }
        }
    }
    printf("%d\n%d ", d[K]-1, N);
    f(K);
}