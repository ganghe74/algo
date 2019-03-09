#include <iostream>
using namespace std;
int getsum(int n, int base) {
    if (n == 0) return 0;
    return getsum(n / base, base) + n % base;
}
int main() {
    for (int i=1000;i<10000;++i) {
        if (getsum(i, 10) == getsum(i, 12) && getsum(i, 12) == getsum(i, 16)) printf("%d\n", i);
    }
}