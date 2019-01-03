#include <iostream>
using namespace std;
int main() {
    int e, f, c, nyam = 0;
    scanf("%d%d%d", &e, &f, &c);
    e += f;
    while (e >= c) {
        nyam += e/ c;
        e = e % c + e / c;
    }
    printf("%d", nyam);
}