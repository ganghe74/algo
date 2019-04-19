#include <iostream>
using namespace std;

bool isit(int n) {
    while (n > 0) {
        if (n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    while (!isit(N)) N--;
    printf("%d", N);
}