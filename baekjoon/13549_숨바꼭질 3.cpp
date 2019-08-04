#include <bits/stdc++.h>
using namespace std;

int d[200001];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    queue<int> q;
    q.push(N);
    d[N] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next=now*2;next<=200000;next*=2) {
            if (next == 0) break;
            if (!d[next]) {
                q.push(next);
                d[next] = d[now];
            }
        }
        for (int next : {now-1, now+1}) {
            if (0 <= next && next <= 200000) {
                if (!d[next]) {
                    q.push(next);
                    d[next] = d[now] + 1;
                }
            }
        }
    }
    printf("%d", d[K]-1);
}