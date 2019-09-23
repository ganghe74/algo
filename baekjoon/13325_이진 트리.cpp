#include <bits/stdc++.h>
using namespace std;

int k, tree[1<<21], winner[1<<21];
int ans;

int main() {
    scanf("%d", &k);
    for (int i=2;i<=(1<<k+1)-1;++i) {
        scanf("%d", &tree[i]);
        ans += tree[i];
    }
    for (int i=(1<<k)-1;i>=1;--i) {
        winner[i] = max(winner[2*i] + tree[2*i], winner[2*i+1] + tree[2*i+1]);
    }
    for (int i=2;i<=(1<<k+1)-1;++i) {
        ans += winner[i/2] - winner[i] - tree[i];
    }
    printf("%d", ans);
}