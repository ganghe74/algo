#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int a[8], b[8];
void go(int minIdx, int len) {
    if (len == M) {
        for (int i=0;i<M;++i) printf("%d ", b[i]);
        puts("");
        return;
    }
    for (int i=minIdx;i<N;++i) {
        b[len] = a[i];
        go(i, len+1);
    }
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    int idx = 0;
    for (int i=0;i<N;++i) {
        if (a[i] == 0) continue;
        int num = a[i];
        for (int j=0;j<N;++j) {
            if (a[j] == num) a[j] = 0;
        }
        a[idx++] = num;
    }
    N = idx;
    go(0, 0);
}