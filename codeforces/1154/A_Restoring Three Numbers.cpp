#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a = 0, b, c;
    int arr[4];
    for (int i=0;i<4;++i) scanf("%d", &arr[i]);
    sort(arr, arr+4);
    while (++a) {
        b = arr[0] - a;
        c = arr[1] - a;
        if (arr[2] == b + c && arr[3] == a + b + c) break;
    }
    printf("%d %d %d", a, b, c);
}