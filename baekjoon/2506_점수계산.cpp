#include <iostream>
using namespace std;
int main() {
    int N, ox, ans = 0, sum = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &ox);
        if (ox == 1) ans += ++sum;
        else sum = 0;
    }
    printf("%d", ans);
}