#include <iostream>
using namespace std;
int main() {
    int T, num, bro;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &num, &bro);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", num/bro, num%bro);
    }
}