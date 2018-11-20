#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[5], sum = 0;
    for (int i=0;i<5;++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a+5);
    printf("%d\n%d", sum/5, a[2]);
}