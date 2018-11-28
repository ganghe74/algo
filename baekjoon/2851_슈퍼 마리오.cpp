#include <iostream>
#define abs(a) (((a)>0)?(a):-(a))
using namespace std;
int main() {
    int a[11] = {0};
    for (int i=0;i<10;++i) scanf("%d", &a[i]);
    int temp, sum = 0;
    for (int i=0;i<11;++i) {
        temp = a[i];
        if (sum + a[i] >= 100) break;
        sum += a[i];
    }
    if (abs(sum + temp - 100) <= abs(sum - 100)) sum = sum + temp;
    printf("%d", sum);
}