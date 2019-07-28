#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
    int N, h;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &h);
        int idx = 0, cnt = 0;
        while (cnt < h) {
            if (a[idx] == 0) cnt++;
            idx++;
        }
        while (a[idx] != 0) idx++;
        a[idx] = i+1;
    }
    for (int i=0;i<N;++i) printf("%d ", a[i]);
}