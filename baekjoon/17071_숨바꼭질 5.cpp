#include <bits/stdc++.h>
using namespace std;

int d0[500001], d1[500001];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    queue<pair<int,int>> q;
    q.push({N, 2});
    d0[N] = 2;

    while (!q.empty()) {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= 500000) {
                if (dist % 2 == 0) {
                    if (!d1[next]) {
                        d1[next] = dist + 1;
                        q.push({next, dist+1});
                    }
                }
                else {
                    if (!d0[next]) {
                        d0[next] = dist + 1;
                        q.push({next, dist+1});
                    }
                }
            }
        }
    }
    for (int t=0;K+t<=500000;t++) {
        K += t;
        if (t % 2 == 0) {
            if (d0[K] && t >= d0[K] - 2) {
                printf("%d", t);
                return 0;
            }
        }
        else {
            if (d1[K] && t >= d1[K] - 2) {
                printf("%d", t);
                return 0;
            }
        }
    }
    puts("-1");
}