#include <iostream>
using namespace std;
int main() {
    int n, T, num, ans = -1, sum = 0;
    scanf("%d%d", &n, &T);
    for (int i=0;i<n;++i) {
        scanf("%d", &num);
        sum += num;
        if (sum <= T) ans = i;
    }
    printf("%d", ans+1);
}