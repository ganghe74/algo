#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}
int lcm(int a, int b, int c) {
    return lcm(lcm(a,b),c);
}
int main() {
    int ans = 987654321;
    int a[5];
    for (int i=0;i<5;++i) scanf("%d", &a[i]);
    for (int i=0;i<=2;++i) {
        for (int j=i+1;j<=3;++j) {
            for (int k=j+1;k<=4;++k) {
                ans = min(ans, lcm(a[i], a[j], a[k]));
            }
        }
    }
    printf("%d", ans);
}