#include <iostream>
using namespace std;
bool d[1000001];
int main() {
    for (int i=2;i<1000001;++i) {
        if (!d[i]) {
            for (int j=2;j*i<1000001;++j) d[i*j] = 1;
        }
    }
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i=3;i<n;++i) {
            if (!d[i] && !d[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
}