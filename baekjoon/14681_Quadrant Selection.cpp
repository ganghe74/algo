#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > 0) {
        if (y > 0) puts("1");
        else puts("4");
    }
    else {
        if (y > 0) puts("2");
        else puts("3");
    }
}