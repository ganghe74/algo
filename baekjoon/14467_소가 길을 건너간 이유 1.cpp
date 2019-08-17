#include <iostream>
using namespace std;
int cow[11];
int main() {
    for (int i=0;i<=10;++i) cow[i] = -1;
    int n, num, p, move = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &num, &p);
        if (cow[num] != -1 && cow[num] != p) move++;
        cow[num] = p;
    }
    printf("%d", move);
}