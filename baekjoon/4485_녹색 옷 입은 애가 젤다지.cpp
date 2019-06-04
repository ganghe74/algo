#include <bits/stdc++.h>
using namespace std;
int a[125][125], d[125][125];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main() {
    int N, p = 1;
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        memset(a, 0, sizeof(a));
        memset(d, -1, sizeof(d));
        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
        }
        priority_queue<tuple<int,int,int>> pq;
        pq.push({-a[0][0],0,0});
        d[0][0] = a[0][0];
        while (!pq.empty()) {
            int dist, r, c;
            tie(dist, r, c) = pq.top();
            dist = -dist;
            pq.pop();
            for (int k=0;k<4;++k) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                    int nextDist = dist + a[nr][nc];
                    if (d[nr][nc] == -1 || nextDist < d[nr][nc]) {
                        d[nr][nc] = nextDist;
                        pq.push({-nextDist, nr, nc});
                    }
                }
            }
        }
        printf("Problem %d: %d\n", p++, d[N-1][N-1]);
    }
}