#include <bits/stdc++.h>
using namespace std;

int n, paper[1000];

int count(int k) {
    int ret = 0;
    for (int i=0;i<n;++i)
        if (paper[i] >= k) ret++;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &paper[i]);
    int l = 0, r = n;
    while (l < r) {
        int k = (l+r)/2;
        if (count(k) >= k) l = k+1;
        else r = k-1;
    }
    while (count(l+1) >= l+1) l++;
    while (!(count(l) >= l)) l--;
    printf("%d", l);
}