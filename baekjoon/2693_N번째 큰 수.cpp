#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    int a[10];
    scanf("%d", &T);
    while (T--) {
        for (int i=0;i<10;++i) scanf("%d", &a[i]);
        sort(a, a+10);
        printf("%d\n", a[7]);
    }
}