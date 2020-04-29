#include <bits/stdc++.h>
using namespace std;

int n, k, x, mcnt[200001], c[200001];

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        mcnt[x]++;
    }
    for (int i=1;i<=k;++i) scanf("%d", &c[i]);

    vector<vector<int>> ans;
    int idx = 0;
    int before_c = 0;

    for (int i=k;i>=1;--i) {
        if (mcnt[i]) {
            if (before_c != c[i]) idx = 0;
            while (mcnt[i]) {
                if (idx < ans.size()) {
                    while (mcnt[i] && ans[idx].size() < c[i]) {
                        ans[idx].push_back(i);
                        mcnt[i]--;
                    }
                    if (ans[idx].size() == c[i]) idx++;
                }
                else ans.push_back({});
            }
            before_c = c[i];
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto &arr : ans) {
        printf("%d ", (int)arr.size());
        for (int x : arr) printf("%d ", x);
        puts("");
    }

}
