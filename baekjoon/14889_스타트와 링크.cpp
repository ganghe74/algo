#include <bits/stdc++.h>
using namespace std;
int N, s[20][20];
bool c[20];
int ans = 1e9;

void choice(int idx, int cnt) {
    if (cnt == 0) {
        vector<int> t1, t2;
        for (int i=0;i<N;++i) {
            if (c[i]) t1.push_back(i);
            else t2.push_back(i);
        }
        int s1 = 0, s2 = 0;
        for (int i=0;i<t1.size();++i) {
            for (int j=0;j<i;++j) {
                s1 += s[t1[i]][t1[j]] + s[t1[j]][t1[i]];
                s2 += s[t2[i]][t2[j]] + s[t2[j]][t2[i]];
            }
        }
        ans = min(ans, abs(s1-s2));
        return;
    }
    for (int i=idx;i<=N-cnt;++i) {
        if (!c[i]) {
            c[i] = 1;
            choice(i+1, cnt-1);
            c[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &s[i][j]);
    }
    choice(0, N/2);
    printf("%d", ans);
}