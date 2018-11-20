#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int N, first, other;
    scanf("%d", &N);
    scanf("%d", &first);
    for (int i=0;i<N-1;++i) {
        scanf("%d", &other);
        int gcdnum = gcd(first, other);
        printf("%d/%d\n", first/gcdnum, other/gcdnum);
    }
}