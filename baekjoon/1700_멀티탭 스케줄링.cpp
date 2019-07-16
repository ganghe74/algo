#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, ans = 0;
    scanf("%d%d", &N, &K);
    vector<int> a(K), tap(N);
    for (int i=0;i<K;++i) scanf("%d", &a[i]);
    for (int i=0;i<K;++i) {
        if (count(tap.begin(), tap.end(), a[i]) == 0) {
            auto it = find(tap.begin(), tap.end(), 0);
            if (it != tap.end()) {
                *it = a[i];
            }
            else {
                int last = 0;
                auto lastit = a.begin();
                for (int j=0;j<N;++j) {
                    it = find(a.begin(), a.end(), tap[j]);
                    if (it > lastit) {
                        last = j;
                        lastit = it;
                    }
                }
                tap[last] = a[i];
                ans++;
            }
        }
        a[i] = 0;
    }
    printf("%d", ans);
}