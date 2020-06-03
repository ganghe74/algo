#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int ret = 0;
    int ndigit = 1;
    int pow10 = 10;
    while (x >= pow10) {
        ret += ndigit * (pow10 - pow10/10);
        ndigit++;
        pow10 *= 10;
    }
    ret += ndigit * (x - pow10/10 + 1);
    return ret;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (f(n) < k) {
        puts("-1");
        return 0;
    }

    int lo = 0, hi = n;
    while (lo+1 < hi) {
        int mid = (lo+hi)/2;
        if (f(mid) < k) lo = mid;
        else hi = mid;
    }
    printf("%c", to_string(hi)[k-f(lo)-1]);
}
