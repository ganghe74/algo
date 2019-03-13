#include <iostream>
using namespace std;
int N, M;
int a[8];
void go(int l, int now = 0) {
    if (now == M) {
        for (int i=0;i<M;++i) printf("%d ", a[i]);
        puts("");
    }
    for (int i=l;i<N;++i) {
        a[now] = i+1;
        go(i+1, now+1);
    }
}
int main() {
    scanf("%d%d", &N, &M);
    go(0);
}