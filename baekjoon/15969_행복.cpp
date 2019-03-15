#include <iostream>
using namespace std;
int a[1000];
int main() {
    int N, mi = 1000, ma = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=0;i<N;++i) {
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }
    printf("%d", ma-mi);
}