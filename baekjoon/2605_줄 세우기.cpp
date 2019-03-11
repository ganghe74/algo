#include <iostream>
using namespace std;
int main() {
    int n, move;
    scanf("%d", &n);
    int a[n];
    for (int i=0;i<n;++i) a[i] = i+1;
    for (int i=0;i<n;++i) {
        scanf("%d", &move);
        for (int j=i;j>i-move;--j) swap(a[j], a[j-1]);
    }
    for (int i=0;i<n;++i) printf("%d ", a[i]);
}