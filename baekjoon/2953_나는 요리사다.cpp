#include <iostream>
using namespace std;
int a[5];
int main() {
    int n, maxIdx = 0;
    for (int i=0;i<5;++i) {
        for (int j=0;j<4;++j) {
            scanf("%d", &n);
            a[i] += n;
        }
        if (a[maxIdx] < a[i]) maxIdx = i;
    }
    printf("%d %d", maxIdx+1, a[maxIdx]);
}