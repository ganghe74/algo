#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
    int N, h;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &h);
        int idx = 0;
        while (h--) {
            while (a[idx]) idx++;
            idx++;
        }
        while (a[idx]) idx++;
        a[idx] = i+1;
    }
    for (int i=0;i<N;++i) printf("%d ", a[i]);
}