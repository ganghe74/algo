#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, mat[50][50];

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(mat, 0, sizeof(mat));
        scanf("%d%d%d%d", &n, &m, &a, &b);

        priority_queue<pair<int,int>> pq;
        for (int i=0;i<m;++i)
            pq.push({b, i});


        bool flag = true;
        for (int i=0;i<n;++i) {
            int rem = a;

            while (rem > 0 && !pq.empty()) {
                auto [colrem, colidx] = pq.top(); pq.pop();
                mat[i][colidx] = 1;
                rem--;
                if (colrem > 1)
                    pq.push({colrem-1, colidx});
            }

            if (rem > 0) {
                flag = false;
                break;
            }
        }
        if (!pq.empty()) flag = false;
        if (flag) {
            puts("YES");
            for (int i=0;i<n;++i) {
                for (int j=0;j<m;++j) printf("%d", mat[i][j]);
                puts("");
            }
        }
        else puts("NO");
    }
}
