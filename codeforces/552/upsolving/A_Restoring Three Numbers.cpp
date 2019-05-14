#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[4];
    for (int i=0;i<4;++i) scanf("%d", &a[i]);
    sort(a, a+4);
    printf("%d %d %d", a[3]-a[0], a[3]-a[1], a[3]-a[2]);
}