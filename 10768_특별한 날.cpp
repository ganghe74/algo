#include <iostream>
using namespace std;
int main() {
    int m, d;
    scanf("%d%d", &m, &d);
    int a = m * 100 + d;
    if (a > 218) puts("After");
    if (a < 218) puts("Before");
    if (a == 218) puts("Special");
}