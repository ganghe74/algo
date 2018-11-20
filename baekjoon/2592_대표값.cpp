#include <iostream>
using namespace std;
int count[100];
int main() {
    int a[10], sum = 0;
    for (int i=0;i<10;++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        count[a[i]/10] += 1;
    }
    printf("%d\n", sum/10);
    int most = 0;
    for (int i=0;i<10;++i) {
        if (count[most] < count[i]) most = i;
    }
    printf("%d", most*10);
}