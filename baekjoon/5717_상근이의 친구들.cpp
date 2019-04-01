#include <iostream>
using namespace std;
int main() {
    int M, F;
    while (true) {
        scanf("%d%d", &M, &F);
        if (M == 0 && F == 0) break;
        printf("%d\n", M+F);
    }
}