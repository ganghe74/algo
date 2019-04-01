#include <iostream>
using namespace std;
int main() {
    char x;
    int V, A = 0, B = 0;
    scanf("%d ", &V);
    while (V--) {
        scanf("%c", &x);
        if (x == 'A') A++;
        else B++;
    }
    if (A > B) puts("A");
    else if (A < B) puts("B");
    else puts("Tie");
}