#include <iostream>
using namespace std;
int main() {
    int temp, min = 100, sum = 0;
    for (int i=0;i<7;++i) {
        scanf("%d", &temp);
        if (temp%2 == 1) {
            sum += temp;
            if (min > temp) min = temp;
        }
    }
    if (sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
}