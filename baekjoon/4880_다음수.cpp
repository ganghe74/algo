#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    while (true) {
        scanf("%d%d%d", &a, &b, &c);
        if (0 == a && a == b && b == c) break;
        if (a + c == 2 * b) printf("AP %d\n", 2*c-b);
        else printf("GP %d\n", c*(c/b));
    }
}