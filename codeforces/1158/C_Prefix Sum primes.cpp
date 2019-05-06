#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a[2] = {0,0};
    int n, tmp;
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &tmp);
        a[tmp-1]++;
    }

    if (a[1] > 0) {
        printf("2 ");
        a[1]--;
    }
    if (a[0] > 0) {
        printf("1 ");
        a[0]--;
    }
    while (a[1] > 0) {
        printf("2 ");
        a[1]--;
    }
    while (a[0] > 0) {
        printf("1 ");
        a[0]--;
    }
}