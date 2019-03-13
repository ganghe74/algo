#include <iostream>
using namespace std;
int N, M;
int a[8];
void go(int minimum, int len) {
    if (len == M) {
        for (int i=0;i<M;++i) printf("%d ", a[i]);
        puts("");
        return;
    }
    for (int i=minimum;i<=N;++i) {
        a[len] = i;
        go(i, len+1);
    }
}
int main() {
    scanf("%d%d", &N, &M);
    go(1,0);
}