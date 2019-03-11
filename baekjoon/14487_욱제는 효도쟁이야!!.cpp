#include <iostream>
using namespace std;
int main() {
    int n, tmp, m = 0, sum = 0;
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &tmp);
        sum += tmp;
        m = max(m, tmp);
    }
    printf("%d", sum - m);
}