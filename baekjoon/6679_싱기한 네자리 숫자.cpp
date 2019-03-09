#include <iostream>
using namespace std;
int getsum(int n, int base) {
    int r, sum = 0;
    while (n >= base) {
        r = n % base;
        n /= base;
        sum += r;
    }
    return sum + n;
}
int main() {
    for (int i=1000;i<10000;++i) {
        int a = getsum(i, 10);
        int b = getsum(i, 12);
        int c = getsum(i, 16);
        if (a == b && b == c) printf("%d\n", i);
    }
}