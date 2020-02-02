#include <bits/stdc++.h>
using namespace std;
int x, y, d, p;
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    p = x;
    for (int i=1;p!=y;i*=-2) {
        while (p < x + i && p != y) {
            p++; d++;
        }
        while (p > x + i && p != y) {
            p--; d++;
        }
    }
    printf("%d", d);
}
