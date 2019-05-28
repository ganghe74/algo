#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
void solve(int idx, int sum) {
    if (idx == N-1) {
        cnt++;
        return;
    }
    for (int i=0;i+sum<=M;++i) {
        solve(idx+1, sum+i);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    M -= N;
    solve(0,0);
    printf("%d", cnt);
}