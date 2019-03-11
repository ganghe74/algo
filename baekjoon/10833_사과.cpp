#include <iostream>
using namespace std;
int main() {
    int N, a, b, sum = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &a, &b);
        sum += b % a;
    }
    printf("%d", sum);
}