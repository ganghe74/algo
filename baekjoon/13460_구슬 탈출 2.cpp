#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int N, M, rr, rc, br, bc, d[10][10][10][10];
char ch, a[10][10];

int main() {
    memset(d, 0x7f, sizeof(d));
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf(" %c", &ch);
            if (ch == '#') a[i][j] = '#';
            else if (ch == 'O') a[i][j] = 'O';
            else {
                a[i][j] = '.';
                if (ch == 'R') {
                    rr = i;
                    rc = j;
                }
                if (ch == 'B') {
                    br = i;
                    bc = j;
                }
            }
        }
    }

    d[rr][rc][br][bc] = 0;
    queue<tuple<int,int,int,int,int>> q;
    q.push({rr, rc, br, bc, 0});
    while (!q.empty()) {
        for (int k=0;k<4;++k) {
            auto [rr, rc, br, bc, dist] = q.front();
            if (dist >= 10) break;
            a[rr][rc] = '#';
            a[br][bc] = '#';
            int nrr = rr + dr[k];
            int nrc = rc + dc[k];
            int nbr = br + dr[k];
            int nbc = bc + dc[k];
            
            bool red_escaped = false;
            bool blue_escaped = false;
            while (a[nrr][nrc] != '#' || a[nbr][nbc] != '#') {
                if (a[nbr][nbc] == 'O') {
                    blue_escaped = true;
                    break;
                }
                if (a[nrr][nrc] == 'O') {
                    red_escaped = true;
                    a[rr][rc] = '.';
                    nrr = nrc = 0;
                }
                if (!red_escaped && a[nrr][nrc] == '.') {
                    a[nrr][nrc] = '#';
                    a[rr][rc] = '.';
                    rr = nrr; rc = nrc;
                    nrr += dr[k]; nrc += dc[k];
                }
                if (a[nbr][nbc] == '.') {
                    a[nbr][nbc] = '#';
                    a[br][bc] = '.';
                    br = nbr; bc = nbc;
                    nbr += dr[k]; nbc += dc[k];
                }
            }
            a[rr][rc] = a[br][bc] = '.';
            if (red_escaped && !blue_escaped) {
                printf("%d", dist+1);
                return 0;
            }
            if (!blue_escaped && dist+1 < d[rr][rc][br][bc]) {
                d[rr][rc][br][bc] = dist + 1;
                q.push({rr, rc, br, bc, dist+1});
            }
        }
        q.pop();
    }
    puts("-1");
}
