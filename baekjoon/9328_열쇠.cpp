#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int T, h, w;
char a[102][102], s[30];
bool visited[102][102];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &h, &w);
        for (int i=1;i<=h;++i)
            for (int j=1;j<=w;++j) scanf(" %c", &a[i][j]);
        for (int i=0;i<=w+1;++i) a[0][i] = a[h+1][i] = '.';
        for (int i=0;i<=h+1;++i) a[i][0] = a[i][w+1] = '.';

        int cnt = 0, next_status = 0, status = -1;
        scanf(" %s", s);
        if (s[0] != '0')
            for (int i=0;s[i] != '\0';++i) next_status |= (1 << (s[i] - 'a'));

        queue<pair<int,int>> q;

        while (status != next_status) {
            memset(visited, 0, sizeof(visited));
            status = next_status;
            q.push({0, 0});

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int k=0;k<4;++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (0 <= nr && nr <= h+1 && 0 <= nc && nc <= w+1) {
                        if (!visited[nr][nc]) {
                            if (a[nr][nc] == '*') continue;
                            if (isupper(a[nr][nc]))
                                if (!(status & (1 << (a[nr][nc] - 'A')))) continue;
                            if (islower(a[nr][nc]))
                                next_status |= (1 << (a[nr][nc] - 'a'));
                            if (a[nr][nc] == '$') {
                                a[nr][nc] = '.';
                                cnt++;
                            }
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
}
