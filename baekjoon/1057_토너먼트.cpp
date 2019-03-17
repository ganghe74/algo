#include <iostream>
using namespace std;
int main() {
    int N, a, b, round = 0;
    scanf("%d%d%d", &N, &a, &b);
    a--, b--;
    while (a != b) {
        a /= 2;
        b /= 2;
        round++;
    }
    printf("%d", round);
}