#include <bits/stdc++.h>
using namespace std;
int N, a[1000], d[1000], before[1000];
void print(int now) {
    if (before[now] != -1) print(before[now]);
    printf("%d ", a[now]);
}
int main() {
    fill(before, before+1000, -1);
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=0;i<N;++i) {
        d[i] = 1;
        for (int j=0;j<i;++j) {
            if (a[i] > a[j] && d[j]+1 > d[i]) {
                d[i] = d[j] + 1;
                before[i] = j;
            }
        }
    }
    int Midx = 0;
    for (int i=0;i<N;++i)
        if (d[i] > d[Midx]) Midx = i;
    printf("%d\n", d[Midx]);
    print(Midx);
}