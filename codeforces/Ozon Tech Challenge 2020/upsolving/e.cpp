#include <bits/stdc++.h>
using namespace std;

int n, m, a[5000];
unordered_map<int,bool> c;

int main() {
    scanf("%d%d", &n, &m);
    int limit = (n/2) * (n/2);
    if (n % 2 == 0) limit -= n / 2;

    if (m > limit) {
        puts("-1");
        return 0;
    }

    int idx = 0, num = 1;
    while (m >= (num-1)/2) {
        m -= (num-1)/2;
        a[idx++] = num++;
    }

    if (m) {
        a[idx++] = num - 1 + num - 2 * m;
    }

    for (int i=0;i<idx;++i)
        for (int j=i+1;j<idx;++j)
            c[a[i] + a[j]] = 1;

    num = a[idx-1] + 1;

    while (idx < n) {
        while (c[num]) num++;
        a[idx] = num++;
        for (int i=0;i<idx;++i) c[a[i] + a[idx]] = 1;
        idx++;
    }

    for (int i=0;i<n;++i) printf("%d ", a[i]);
}
