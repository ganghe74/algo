#include <iostream>
#define max(a,b) ((a)>(b))?(a):(b)
using namespace std;
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c) printf("%d", 10000 + 1000 * a);
    else if (a == b) printf("%d", 1000 + 100 * a);
    else if (a == c) printf("%d", 1000 + 100 * a);
    else if (b == c) printf("%d", 1000 + 100 * b);
    else printf("%d", 100 * (max(a,max(b,c))));
}