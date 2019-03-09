#include <iostream>
using namespace std;
int main() {
    int X, cnt = 0, stick = 64;
    scanf("%d", &X);
    while (X > 0) {
        if (stick <= X) X -= stick, cnt++;
        else stick /= 2;
    }
    printf("%d", cnt);
}