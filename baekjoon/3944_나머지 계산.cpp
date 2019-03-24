#include <iostream>
using namespace std;
int main() {
    int T, B;
    scanf("%d", &T);
    while (T--) {
        char x;
        int num = 0;
        scanf("%d ", &B);
        for (x=getchar();x!='\n';) {
            num = num * B + x - '0';
            num %= B-1;
            x = getchar();
        }
        printf("%d\n", num);
    }
}