#include <iostream>
using namespace std;
int count[100] = {0};
int main() {
    int a[10], sum = 0;
    for (int i=0;i<10;++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        count[a[i]/10] += 1;
    }
    int most = 0;
    for (int i=0;i<100;++i) {
        if (count[most] < count[i]) most = i;
    }
    printf("%d\n%d", sum/10, most*10);
}