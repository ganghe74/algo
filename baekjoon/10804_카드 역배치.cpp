#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int card[20];
    for (int i=0;i<20;++i) card[i] = i+1;
    int a, b;
    for (int i=0;i<10;++i) {
        scanf("%d %d", &a, &b);
        reverse(card + a - 1, card + b);
    }
    for (int i=0;i<20;++i) printf("%d ", card[i]);
}