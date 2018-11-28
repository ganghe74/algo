#include <iostream>
using namespace std;

int solve(int n) {
    int divisor = 10;
    while (n > divisor) {
        if (n%divisor >= divisor/2) n = n/divisor*divisor + divisor;
        else n = n/divisor*divisor;
        divisor *= 10;
    }
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", solve(temp));
    }
}