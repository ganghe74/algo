#include <iostream>
using namespace std;
int main() {
    int maxIdx = 0;
    int a[81];
    for (int i=0;i<81;++i) {
        scanf("%d", &a[i]);
        if (a[i] > a[maxIdx]) {
            maxIdx = i;
        }
    }
    printf("%d\n%d %d", a[maxIdx], maxIdx/9+1, maxIdx-maxIdx/9*9+1);
}