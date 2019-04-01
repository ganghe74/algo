#include <iostream>
using namespace std;
int main() {
    int w, h, p, q, t, x, y;
    scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);
    x = (t+p) % (2*w);
    if (x > w) x = 2*w-x;
    y = (t+q) % (2*h);
    if (y > h) y = 2*h-y;
    printf("%d %d", x, y);
}