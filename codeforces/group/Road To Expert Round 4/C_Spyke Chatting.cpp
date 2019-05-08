#include <bits/stdc++.h>
using namespace std;

bool c[20000][10];
int ans[20000];
int cnt[10];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) scanf("%d", &c[i][j]);
    }

    while (k--) {
        int sender, chat;
        scanf("%d%d", &sender, &chat);
        sender--; chat--;
        ans[sender]--;
        cnt[chat]++;
    }
    for (int i=0;i<m;++i) {
        for (int j=0;j<n;++j) {
            if (c[j][i]) ans[j] += cnt[i];
        }
    }
    for (int i=0;i<n;++i) printf("%d ", ans[i]);
}