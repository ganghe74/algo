#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int l, c, k, x;
vector<int> a;

bool f(int len, int pidx=0) {
    int rem = c;
    for (int i=pidx+1;i<=k+1;++i) {
        if (a[i] - a[pidx] > len) {
            if (a[i] - a[i-1] > len) return false;
            rem--;
            pidx = i-1;
        }
        if (rem < 0) return false;
    }
    return true;
}

int main() {
    scanf("%d%d%d", &l, &k, &c);
    a = {0, l};
    for (int i=0;i<k;++i) {
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    int lo=0, hi=l;

    while (lo + 1 < hi) {
        int mid = (lo+hi)/2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }

    int n = lower_bound(a.begin(), a.end(), hi) - a.begin();
    int mincut = a[n];
    c--;
    for (int i=1;i<n;++i) {
        if (f(hi, i)) {
            mincut = a[i];
            break;
        }
    }

    printf("%d %d", hi, mincut);
}
