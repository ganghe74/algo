#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10], c[10];
void go(int N, int M, int now = 0) {
    if (now == M) {
        for (int i=0;i<M;++i) printf("%d ", a[i]);
        puts("");
        return;
    }
    for (int i=1;i<=N;++i) {
        if (!c[i]) {
            c[i] = true;
            a[now] = i;
            go(N, M, now+1);
            c[i] = false;
        }
    }
}
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    go(N, M);
}