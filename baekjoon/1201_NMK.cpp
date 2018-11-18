#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<int> a(N);
    if (M+K-1 <= N && N <= M*K) {
        for (int i=0;i<N;++i) a[i] = i+1;
        vector<int> g;
        g.push_back(0);
        g.push_back(K);
        N -= K;
        M -= 1;
        int gs = M == 0 ? 1 : N/M;
        int r = M == 0 ? 0 : N%M;
        for (int i=0;i<M;++i) {
            g.push_back(g.back()+gs + (r > 0 ? 1 : 0));
            if (r > 0) r-= 1;
        }
        for (int i=0;i<g.size()-1;++i) {
            reverse(a.begin()+g[i], a.begin()+g[i+1]);
        }
        for (int i=0;i<a.size();++i) {
            printf("%d ", a[i]);
        }
    }
    else {
        printf("-1");
    }
}