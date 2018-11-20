#include <iostream>
using namespace std;
int main() {
    int L, P, news;
    scanf("%d %d", &L, &P);
    for (int i=0;i<5;++i) {
        scanf("%d", &news);
        printf("%d ", news - L*P);
    }
}