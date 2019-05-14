#include <iostream>
using namespace std;

int f(int n) {
    ++n;
    while (n % 10 == 0) n /= 10;
    return n;
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    while (n > 9) {
        n = f(n);
        cnt++;
    }
    printf("%d", cnt + 9);
}