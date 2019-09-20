#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, x, before, cnt_inc = 1, cnt_dec = 1, ans = 1;
    scanf("%d%d", &N, &before);
    while (--N) {
        scanf("%d", &x);
        if (x >= before) cnt_inc++;
        else cnt_inc = 1;
        if (x <= before) cnt_dec++;
        else cnt_dec = 1;
        ans = max({ans, cnt_inc, cnt_dec});
        before = x;
    }
    printf("%d", ans);
}