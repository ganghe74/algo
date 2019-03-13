#include <iostream>
using namespace std;
int main() {
    int C, N;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        int a[50000], mv[50000];
        for (int i=0;i<N;++i) a[i] = i+1;
        for (int i=0;i<N;++i) scanf("%d", &mv[i]);
        for (int i=N-1;i>=0;--i) {
            for (int j=i-mv[i];j<i;++j) swap(a[j],a[j+1]);
        }
        for (int i=0;i<N;++i) printf("%d ", a[i]);
        puts("");
    }
}