#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int c[8], a[8], b[8];
void go(int len) {
    if (len == M) {
        for (int i=0;i<M;++i) printf("%d ", b[i]);
        puts("");
        return;
    }
    for (int i=0;i<N;++i) {
        if (!c[i]) {
            c[i] = true;
            b[len] = a[i];
            go(len+1);
            c[i] = false;
        }
    }
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    go(0);
}