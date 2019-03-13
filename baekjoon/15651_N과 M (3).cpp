#include <iostream>
using namespace std;
int N, M;
int a[7];
void go(int len) {
    if (len == M) {
        for (int i=0;i<M;++i) printf("%d ", a[i]);
        puts("");
        return;
    }
    for (int i=0;i<N;++i) {
        a[len] = i+1;
        go(len+1);
    }
}
int main() {
    scanf("%d%d", &N, &M);
    go(0);
}