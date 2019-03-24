#include <iostream>
using namespace std;
int main() {
    int T, N, M;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        printf("%d %d\n", M*2-N, N-M);
    }
}