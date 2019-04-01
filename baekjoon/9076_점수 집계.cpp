#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T;
    int a[5];
    scanf("%d", &T);
    while (T--) {
        for (int i=0;i<5;++i) scanf("%d", &a[i]);
        sort(a, a+5);
        if (a[3] - a[1] >= 4) puts("KIN");
        else printf("%d\n", a[1]+a[2]+a[3]);
    }
}