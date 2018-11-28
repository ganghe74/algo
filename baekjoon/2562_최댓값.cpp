#include <iostream>
using namespace std;
int main() {
    int a[9];
    for (int i=0;i<9;++i) scanf("%d", &a[i]);
    int maxIdx = 0;
    for (int i=1;i<9;++i) {
        if (a[maxIdx] < a[i]) maxIdx = i;
    }
    printf("%d\n%d", a[maxIdx], maxIdx+1);
}