#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, d, k;
    cin >> a >> d >> k;
    if ((k-a)%d == 0 && (k-a)/d >= 0) printf("%d", (k-a)/d+1);
    else puts("X");
}