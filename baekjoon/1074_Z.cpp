#include <iostream>
using namespace std;
int power2(int k) {
    return (1 << k);
}
int go(int n, int r, int c) {
    if (n == 1) return 2*r+c;
    else {
        if (r < power2(n-1)) {
            if (c < power2(n-1)) return go(n-1, r, c);
            else return go(n-1, r, c-power2(n-1)) + power2(2*n-2);
        }
        else {
            if (c < power2(n-1)) return go(n-1, r-power2(n-1), c) + 2 * power2(2*n-2);
            else return go(n-1,r-power2(n-1), c-power2(n-1)) + 3 * power2(2*n-2);
        }
    }
}

int main() {
    int N, r, c;
    scanf("%d%d%d", &N,&r,&c);
    printf("%d", go(N,r,c));
}