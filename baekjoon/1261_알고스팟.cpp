#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int a[100][100];
vector<int> d(10000, 1e+9);

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0;i<M;++i) {
        for (int j=0;j<N;++j) scanf("%1d", &a[i][j]);
    }
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    d[0] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        int r = now / 100;
        int c = now % 100;
        pq.pop();
        for (int k=0;k<4;++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (0 <= nr && nr < M && 0 <= nc && nc < N) {
                int next = nr * 100 + nc;
                int nextDist = dist + a[nr][nc];
                if (nextDist < d[next]) {
                    d[next] = nextDist;
                    pq.push({-nextDist, next});
                }
            }
        }
    }
    printf("%d", d[(M-1)*100 + N-1]);
}