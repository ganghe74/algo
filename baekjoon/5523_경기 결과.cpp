#include <iostream>
using namespace std;
int main() {
    int N, a = 0, b = 0;
    scanf("%d", &N);
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) a++;
        if (x < y) b++;
    }
    printf("%d %d", a, b);
}