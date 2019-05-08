#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[100], b[100];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<k;++i) scanf("%d", &b[i]);
    sort(b, b+k);

    bool inc = true;
    for (int i=0;i<n;++i) {
        if (a[i] == 0) a[i] = b[--k];
    }
    for (int i=0;i<n-1;++i) {
        if (a[i] > a[i+1]) inc = false;
    }
    if (inc) puts("No");
    else puts("Yes");
}