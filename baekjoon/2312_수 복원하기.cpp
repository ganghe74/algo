#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, divisor = 2;
        int a[100001] = {0};
        scanf("%d", &N);
        while (N != 1) {
            while (N % divisor == 0) {
                N /= divisor;
                a[divisor]++;
            }
            divisor++;
        }
        for (int i=2;i<100000;++i) {
            if (a[i] > 0) printf("%d %d\n", i, a[i]);
        }
    }
}