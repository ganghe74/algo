#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int W[N][N];
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            int w;
            scanf("%d", &w);
            W[i][j] = w;
        }
    }
    vector<int> a(N);
    for (int i=0;i<N;++i) a[i] = i;
    int ans = 987654321;
    do {
        bool ok = true;
        int sum = 0;
        for (int i=0;i<N-1;++i) {
            if (W[a[i]][a[i+1]] == 0) ok = false;
            else sum += W[a[i]][a[i+1]];
        }
        if (ok && W[a[N-1]][a[0]]) {
            sum += W[a[N-1]][a[0]];
            if (ans > sum) ans = sum;
        }
    } while(next_permutation(a.begin()+1, a.end()));
    printf("%d", ans);
}