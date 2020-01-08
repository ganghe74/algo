#include <bits/stdc++.h>
using namespace std;
int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    x1 = min(x1, x3);
    x2 = max(x2, x4);
    y1 = min(y1, y3);
    y2 = max(y2, y4);
    int l = max(x2-x1, y2-y1);
    printf("%d", l*l);
}