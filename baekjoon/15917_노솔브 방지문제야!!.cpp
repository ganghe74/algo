#include <iostream>
using namespace std;
int main() {
    int Q, a;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &a);
        if (!(a&(a-1))?1:0) printf("1\n");
        else printf("0\n");
    }
}