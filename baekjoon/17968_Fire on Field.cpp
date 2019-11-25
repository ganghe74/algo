#include <bits/stdc++.h>
using namespace std;

int n, a[1001] = {1, 1};

int main() {
    scanf("%d", &n);
    for (int i=2;i<=n;++i) {
        bool c[1001] = {0};
        for (int k=1;i-2*k>=0;++k) {
            int no = 2*a[i-k] - a[i-2*k];
            c[no] = 1;
        }
        int idx=1;
        while (c[idx]) idx++;
        a[i] = idx;
    }
    printf("%d", a[n]);
}