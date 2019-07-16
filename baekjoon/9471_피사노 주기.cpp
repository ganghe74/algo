#include <iostream>
using namespace std;
int main() {
    int P, N, M;
    scanf("%d", &P);
    while (P--) {
        scanf("%d%d", &N, &M);
        int m1 = 1, m2 = 1, c = 0;
        do {
            int temp = (m1 + m2) % M;
            m1 = m2;
            m2 = temp;
            ++c;
        } while (m1 != 1 || m2 != 1);
        printf("%d %d\n", N, c);
    }
}