#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    for (int i=1;i<=T;++i) {
        int a[3];
        for (int j=0;j<3;++j) scanf("%d", &a[j]);
        sort(a, a+3);
        printf("Case #%d: ", i);
        if (a[0] + a[1] <= a[2]) puts("invalid!");
        else if (a[0] == a[1] && a[1] == a[2]) puts("equilateral");
        else if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) puts("isosceles");
        else puts("scalene");
    }
}