#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int y, k, sumY = 0, sumK = 0;
        for (int i=0;i<9;++i) {
            scanf("%d%d", &y, &k);
            sumY += y;
            sumK += k;
        }
        if (sumY > sumK) printf("Yonsei\n");
        else if (sumY < sumK) printf("Korea\n");
        else printf("Draw\n");
    }
}