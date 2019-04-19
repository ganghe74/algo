#include <iostream>
using namespace std;
int main() {
    int N;
    char x;
    scanf("%d ", &N);
    while (N--) {
        x = getchar();
        if (x >= 97) x -= 32;
        while (true) {
            putchar(x);
            if (x == '\n') break;
            x = getchar();
        }
    }
}