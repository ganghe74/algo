#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int r, e, c;
        scanf("%d%d%d", &r, &e, &c);
        if (r < e-c) puts("advertise");
        else if (r == e-c) puts("does not matter");
        else puts("do not advertise");
    }
}