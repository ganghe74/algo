#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int a[9];
    for (int i=0;i<9;++i) scanf("%d", &a[i]), sum += a[i];
    for (int i=0;i<9;++i) {
        for (int j=i+1;j<9;++j)
            if (sum - a[i] - a[j] == 100) {
                for (int k=0;k<9;++k) {
                    if (k == i || k == j) continue;
                    printf("%d\n", a[k]);
                }
                return 0;
            }
    }
}