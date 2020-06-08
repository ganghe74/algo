#include <bits/stdc++.h>
using namespace std;

const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                cin >> a[i][j];
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                if (a[i][j] == 'B') {
                    for (int k=0;k<4;++k) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (0 <= nr && nr < n && 0 <= nc && nc < m)
                            if (a[nr][nc] == '.') a[nr][nc] = '#';
                    }
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<pair<int,int>> q;
        if (a[n-1][m-1] != '#') {
            q.push({n-1, m-1});
            visited[n-1][m-1] = 1;
        }
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k=0;k<4;++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                    if (a[nr][nc] != '#') {
                        if (!visited[nr][nc]) {
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        bool f = true;
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                if (a[i][j] == 'G' && !visited[i][j]) f = false;
                if (a[i][j] == 'B' && visited[i][j]) f = false;
            }
        }

        cout << (f ? "Yes" : "No") << '\n';
    }
}
