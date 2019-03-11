#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, num, sum = 0;
        scanf("%d", &N);
        while (N--) {
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }
}