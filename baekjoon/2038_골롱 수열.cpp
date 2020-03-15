#include <bits/stdc++.h>
using namespace std;

int n, f[1000000];

int main() {
    scanf("%d", &n);
    f[1] = 1; f[2] = 2;
    int k = 2, idx = 2, cnt = 1;
    while (cnt < n) {
        cnt += f[k] * k;
        for (int i=0;i<f[k];++i) f[idx++] = k;
        k++;
    }
    while (cnt - f[--idx] >= n) cnt -= f[idx];
    printf("%d\n", idx);
}
