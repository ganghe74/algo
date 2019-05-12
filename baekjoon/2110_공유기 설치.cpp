#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &a, int c, int x) {
    int cnt = 1;
    int last = a[0];
    for (int house : a) {
        if (house - last >= x) {
            cnt += 1;
            last = house;
        }
    }
    return cnt >= c;
}
int main() {
    int N, C;
    scanf("%d%d", &N, &C);
    vector<int> a(N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int l = 1, r = 1000000000;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (possible(a, C, mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", r);
}