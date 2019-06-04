#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool possible(int len, int amount) {
    int cnt = 0;
    int last = a[0];
    for (int x : a) {
        if (x - last >= len) {
            cnt++;
            last = x;
        }
    }
    return cnt >= amount;
}
int main() {
    int N, M, L, q;
    scanf("%d%d%d", &N, &M, &L);
    a = vector<int>(M+2);
    a[0] = 0; a[M+1] = L;
    for (int i=1;i<=M;++i) scanf("%d", &a[i]);
    while (N--) {
        scanf("%d", &q);
        int l = 0, r = 4000000;
        while (l < r) {
            int mid = (l + r) / 2;
            if (possible(mid, q+1)) l = mid + 1;
            else r = mid -1;
        }
        if (possible(l, q+1)) printf("%d\n", l);
        else printf("%d\n", l-1);
    }
}