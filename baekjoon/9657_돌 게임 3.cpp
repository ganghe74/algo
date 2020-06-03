#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    n %= 7;
    if (n == 0 || n == 2) puts("CY");
    else puts("SK");
}
