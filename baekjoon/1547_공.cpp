#include <iostream>
using namespace std;
int main() {
    int M, x, y, ball = 1;
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &x, &y);
        if (ball == x) ball = y;
        else if (ball == y) ball = x;
    }
    printf("%d", ball);
}